# rpn_calculator

A basic RPN calculator.   
uses `long double` as it's numeric data type.    
`main.cpp` reads calculations from stdin (one per line) and prints the result to the console.   
`test_rpn_calculator.cpp` does unit tests for math functions and parsing.  

Operators:

| name    | function                |
| --------| ----------------------- |
| `+`     | addition                |
| `-`     | subtraction             |
| `/`     | division                |
| `*`     | multiplication          |
| `^2`    | square                  |
| `sqrt`  | square root             |
| `^`     | power                   |
| `pow`   | power                   |
| `rt`    | root                    |
| `root`  | root                    |
| `ln`    | natural logarithm       |
| `log`   | base 10 logarithm       |
| `lg`    | base 2 logarithm        |
| `loga`  | arbirary base logarithm |
| `exp`   | e to power              |
| `exp10` | 10 to poewr             |
| `exp2`  | 2 to power              |
| `sin`   | sine                    |
| `cos`   | cosine                  |
| `tan`   | tangent                 |
| `asin`  | arc sine                |
| `acos`  | arc cosine              |
| `atan`  | arc tangent             |
| `floor` | next smaller integer    |
| `ceil`  | next larger integer     |


Special Functions:  

| name         | function                              |
| ------------ | --------                              |
|`#hex`        | format output as hex float            |
|`#def`        | format output as default              |
|`#default`    | format output as default              |
|`#fix`        | format output as fixed                |
|`#fixed`      | format output as fixed                |
|`#sci`        | format output in scientific notation  |
|`#scientific` | format output in scientific notation  |
|`#max`        | use maximum number of digits          |
|`#maxdigits`  | use maximum number of digits          |
|`#digits`     | use n digits                          |
|`#dig`        | use n digits                          |
|`#define`     | define a variable                     |
|`#d`          | define a variable                     |
|`#tree`       | print a syntax tree for an expression |
|`#t`          | print a syntax tree for an expression |