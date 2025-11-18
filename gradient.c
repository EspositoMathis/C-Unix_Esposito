#include "image.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Image *img = image_create(200, 100);

    if (img == NULL) {
        return 1;
    }

    // Génération du dégradé de bleu
    int b =0;
    for(int i = 0; i<img->height; i++){
        for (int j = 0; j<img->width; j++){
            image_set_pixel(img, j, i, 0, 0, b);            
            b++;
        }
        b=0;
    }

    image_save_txt(img, "gradient.ppm");

    image_free(img);
    return 0;
}
