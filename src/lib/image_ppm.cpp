//
// Created by Soumik Rakshit on 22/01/21.
//

#include "image_ppm.hpp"


void CreatePPMImage(int imageHeight, int imageWidth, std::string filePath) {

    std::ofstream file(filePath);

    file << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for(int j = imageHeight - 1; j >= 0; j--) {

        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for(int i = 0; i < imageWidth; i++) {

            int r = static_cast<int>(255.999 * double(i) / (imageWidth - 1));
            int g = static_cast<int>(255.999 * double(j) / (imageHeight - 1));
            int b = static_cast<int>(255.999 * 0.25);

            file << r << " " << g << " " << b << "\n";
        }
    }

    file.close();
}
