{
  description = "Cpp Types Lib development environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-26.05";
  };

  outputs =
    { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
      pkgsWin = pkgs.pkgsCross.mingwW64;
    in
    {
      devShells.${system} = {
        default = pkgs.mkShell {
          packages = with pkgs; [
            gcc
            cmake
            ninja
            pkg-config
            catch2_3
          ];
        };

        windows = pkgsWin.mkShell {
          packages = with pkgsWin; [
            cmake
            ninja
            pkg-config
          ];
          shellHook = ''
            echo "Windows shell hook"
          '';

          nativeBuildInputs = with pkgs; [
            cmake
            ninja
            pkg-config
          ];
        };
      };
    };
}
