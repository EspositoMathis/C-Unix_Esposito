#include "image.h"
#include <stdlib.h>
#include <string.h>

Image* image_create(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    // TODO
    img->width = width;
    img->height = height;
    img->pixels = (unsigned char*)malloc(width*height*3);
    return img;
}

void image_free(Image *img) {
    if (!img){
        if (img->pixels) free(img->pixels);
        free(img);
    } 
}

void image_set_pixel(Image *img, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (img != NULL && x >= 0 && x < img->width && y >= 0 && y < img->height) {
        int index = (y * img->width + x) * 3;
        img->pixels[index + 0] = r;
        img->pixels[index + 1] = g;
        img->pixels[index + 2] = b;
    }
}

void image_save_txt(Image *img, const char *filename) {
    if (img == NULL) return;
    // TODO
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "P3\n%d %d\n255\n",img->width, img->height);

    for(int i = 0; i<img->height; i++){
        for (int j = 0; j<img->width; j++){
            int index = (i * img->width + j) * 3;
            fprintf(fp, "%d %d %d ",                
                img->pixels[index + 0],
                img->pixels[index + 1],
                img->pixels[index + 2]);
            }
        fprintf(fp,"\n");
    }
    
    fclose(fp);
}

            // printf("image_set_pixel : index:%d r=%d g=%d b=%d\n",index,
            //     img->pixels[index + 0],
            //     img->pixels[index + 1],
            //     img->pixels[index + 2]);