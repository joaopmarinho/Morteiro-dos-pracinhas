#include "structs.h"


typedef struct {
    int x, y;
    float a, b, c;
    bool ativo;
    char img;
    int width, height;
} Bala;

typedef struct {
    char img;
    bool active;
    int x;
    double y;
    int width, height;
    int cont;
} Enemies;