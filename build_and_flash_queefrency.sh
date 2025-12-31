#!/usr/bin/env bash
set -euo pipefail

KEYBOARD="keebio/quefrency/rev3"
KEYMAP="default"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export QMK_HOME="${SCRIPT_DIR}"
cd "${SCRIPT_DIR}"
HEX_BASENAME="${KEYBOARD//\//_}_${KEYMAP}"
HEX_PATH="${SCRIPT_DIR}/${HEX_BASENAME}.hex"

log() {
  printf '[%s] %s\n' "$(date '+%H:%M:%S')" "$*"
}

run_in_env() {
  if [[ -n "${IN_NIX_SHELL:-}" ]]; then
    "$@"
  elif command -v nix >/dev/null 2>&1 && [[ -f flake.nix ]]; then
    nix develop --command "$@"
  else
    "$@"
  fi
}

log "Updating git submodules..."
git submodule update --init --recursive

log "Verifying QMK CLI availability..."
run_in_env qmk --version >/dev/null

log "Building firmware for ${KEYBOARD}:${KEYMAP}..."
run_in_env make "${KEYBOARD}:${KEYMAP}"

if [[ ! -f "${HEX_PATH}" ]]; then
  log "Expected firmware artifact ${HEX_PATH} not found" >&2
  exit 1
fi

log "Firmware ready at ${HEX_PATH}."
log "Flashing firmware (put the board into bootloader mode when prompted)..."
run_in_env qmk flash -kb "${KEYBOARD}" -km "${KEYMAP}" "${HEX_PATH}"

log "Flash complete."
