## Requisitos

- CMake ≥ 3.20
- Compilador C++23
- Ninja
- Catch2 v3

Para utilizar o ambiente de desenvolvimento com Nix:

```bash
nix develop
```

Para compilar o projeto:
```bash
cmake -S . -B build -G Ninja
cmake --build build
```

Rodar testes:

```bash
ctest --test-dir build --output-on-failure
```
