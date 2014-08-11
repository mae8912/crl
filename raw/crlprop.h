#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>


/* some general structures to store parameters */

/* x-ray energy / wavelength */
struct xray {
    double energy;     /* x-ray energy, in keV */
    double wavelength; /* x-ray wavelength, in metre */
    double wavenumber; /* x-ray wavenumber, in inverse metre */
};


/* source parameters */
struct source {
    double distance; /* distance from source to crl device (entrance), in metre */
};

/* crl device parameters */
struct crl {
    double f;            /* focal width of individual lens, in metre */
    double aperture;     /* lateral size of lenses, diametre, in metre */
    double separation;   /* separation distance between lenses, in metre */
    int number;          /* number of lenses inside this crl device */
};

/* detector parameters */
struct detector {
    double distance;   /* distance from crl device (exit), in metre */
    int number;        /* number of pixels */
    double width;      /* width / lateral size of detector, in metre */
    double* intensity; /* array to the propagated intensity */
};

/* collector for all relevant parameter structs */
struct parameters {
    struct xray xray;
    struct source source;
    struct crl crl;
    struct detector detector;
};


/* struct holding a complex-valued field */
struct field {
    int dimensions;         /* number of dimensions */
    int* size;              /* array holding number of points per dimension */
    complex double* values; /* array holding complex valued field */
};


/* parameters to propagate from point-source to crl device */
struct s2c {
    struct xray xray;
    struct source source;
    struct field* field;
};


int source_to_crl(struct s2c* arg);
int crl_inside();
int crl_to_focus();

int print_parameters(struct parameters* para, FILE* f);
int write_field_to_file(struct field* field, const char* fname);

int copy_xray(  struct xray* in,   struct xray* out);
int copy_source(struct source* in, struct source* out);

