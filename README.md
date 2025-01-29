# ExprEval
Projeto para a cadeira Estruturas de Dados Orientado a Objetos (EDOO) CIN0135 2024.2

O programa é um avaliador de expressões, lê expressões (aritméticas e booleanas) da entrada padrão e imprima na saída padrão o resultado da avaliação da expressão lida. O programa usa o algoritmo **recursive descent parser** para isso. 

O formato de cada expressão segue a especificação dada pela **Gramática Livre de Contexto (GLC)**. 

Cada token deve estar separado por pelo menos um espaço **" "** como `( 10 + 3 ( 2 * - 2 ) )` ou `( false || false ) == true` por exemplo.

## Compilando 🛠️
No diretório onde está o `makefile` execute:
```bash
make 
```

Caso prefira pode compilar manualmente (sem Makefile) executando:
```bash
g++ -std=c++17 ./main.cpp ./Expression/expression.cpp ./Expression/binary_expression.cpp ./Expression/unary_expression.cpp ./Operators/operators.cpp ./Literal/literal.cpp ./Parser/parser.cpp -o expreval
```

## Executando
O executável será gerado com o nome `expreval`, execute:
```bash
./expreval
```

## Limpando
Para limpar os arquivos de objeto e o executável, execute:
```bash
make clean
```