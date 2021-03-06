#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define QUAD_TREE_CAPACITY 20
#define MIN_RAD 1.
#define MAX_RAD 2.
#define MIN_MASS 1.
#define MAX_MASS 10.
#define MAX_INIT_VAL 100.
#define ELASTICITY 0.95
#define GRAVITY 0.
#define MAX_GRAV_ACC 1000.
#define NUM_INITIAL 5000
#define SIM_SPEED 1.

typedef struct query_result {
    int *ids, size, allocated;
} query_result_t;

typedef struct quad_tree {
    float qx, qy, qw, qh, cx, cy, total_mass;
    int size, allocated, *id;
    float *x, *y, *w, *h;
    struct quad_tree **sub_trees;
} quad_tree_t;

typedef struct world_state {
    float wx, wy, ww, wh, num;
    float *x, *y, *dx, *dy, *r, *m;
    quad_tree_t *quad_tree;
} world_state_t;

float rand_f();

float fast_inv_sqrt(float);

quad_tree_t *create_quad_tree(float, float, float, float);

int insert_quad_tree(quad_tree_t *, float, float, float, float, int, float);

query_result_t query_quad_tree(quad_tree_t *, float, float, float, float);

void delete_quad_tree(quad_tree_t *);

world_state_t *create_random_world_state(float, float, float, float, int);

world_state_t *create_blank_world_state(float, float, float, float, int);

quad_tree_t *create_quad_tree_from_world_state(world_state_t *);

world_state_t *physics_tick(world_state_t *, float);

void delete_world_state(world_state_t *);

#endif // PHYSICS_H_
