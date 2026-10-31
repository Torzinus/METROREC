# METROREC

**Sincronização de embarque de metrô** - Implementação 5 de Infraestrutura de Software 

## Arquitetura

| Arquivo | Descrição |
|---|---|
| `sync_car.c` | Contém as funções de sincronização: `station_init`, `station_load_car`, `station_wait_for_car` e `station_on_board` |
| `sync_car.h` | Guarda a `struct station` e os protótipos das funções implementadas |
| `sync_car-runner.c` | Programa de teste: cria as threads de carro e de passageiros e valida a implementação |
| `Makefile` | Compila o projeto (gera o executável `sync_car`) e limpa os arquivos gerados |

## Como executar

**1. Clone o repositório**

```bash
git clone "https://github.com/Torzinus/METROREC.git"
```

**2. Compile**

```bash
make clean
make
```

Isso gera o executável `sync_car`.

**3. Execute**

```bash
./sync_car
```

Não é necessário inserir nenhuma entrada durante a execução.

## Como testar

O próprio `./sync_car` executa o teste definido em `sync_car-runner.c`. Para cada carro que passa pela estação, ele imprime quantos assentos havia e quantos passageiros embarcaram, comparando com o valor esperado:

```text
car entering station with 48 free seats
car departed station with 48 new passenger(s) (expected 48)
...
Looks good!
```

A mensagem final `Looks good!` indica que todos os carros partiram com o número esperado de passageiros.

## Ambiente de desenvolvimento

| Item | Versão |
|---|---|
| Sistema operacional | Kali GNU/Linux Rolling 2026.2 (baseado em Debian) |
| Compilador | GCC (Debian 15.2.0-17) 15.2.0 |
| Ferramenta de build | GNU Make 4.4.1 |