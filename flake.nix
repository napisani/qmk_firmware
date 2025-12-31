{
  description = "form uno qmk firmware";

  inputs = {

    flake-utils.url = "github:numtide/flake-utils";
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system};

      in {
        devShells.default = pkgs.mkShell {
          packages = [
            pkgs.qmk
            pkgs.picotool
            (pkgs.python3.withPackages (python-pkgs: [
              python-pkgs.pip
              python-pkgs.platformdirs
              python-pkgs.rpds-py
            ]))
          ];

          shellHook = ''
            echo "qmk"
          '';
        };
      });
}
