[WIP]
=====

##### Running

```
$ make run
cc -std=c11 -O3 -fdiagnostics-color -Wall -pedantic    \
main.c list.c exp.c list.h exp.h  -lm -o main
./main
```

##### Output

```
− (3)
├─÷ (2)
│ ├─a (1)
│ └─+ (1)
│   ├─b (1)
│   └─c (0)
└─× (2)
  ├─d (1)
  └─+ (1)
    ├─e (1)
    └─f (0)
```
