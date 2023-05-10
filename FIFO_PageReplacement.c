#include <stdio.h>

// define the FIFO page replacement function
int fifo(int page_references[], int page_references_size, int page_frames) {
    // initialize the array of page frames to empty
    int frames[page_frames];
    // initialize the array of page faults to zero
    int page_faults = 0;

    // iterate through each page reference in the array of page references
    for (int i = 0; i < page_references_size; i++) {
        // initialize a variable to track if the current page reference is already in a frame
        int in_frame = 0;
        // iterate through each frame to see if the current page reference is already in a frame
        for (int j = 0; j < page_frames; j++) {
            // if the current frame already contains the current page reference, set the in_frame flag to true
            if (frames[j] == page_references[i]) {
                in_frame = 1;
                break;
            }
        }
        // if the current page reference is not already in a frame, add it to the first available frame
        if (!in_frame) {
            // if there are still empty frames, add the current page reference to the next available frame
            if (page_faults < page_frames) {
                frames[page_faults] = page_references[i];
            }
            // if all frames are full, replace the oldest page reference with the current page reference
            else {
                frames[page_faults % page_frames] = page_references[i];
            }
            // increment the number of page faults
            page_faults++;
        }
    }

    // return the total number of page faults
    return page_faults;
}

// test the FIFO page replacement function with some example inputs
int main() {
    int page_references[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int page_references_size = sizeof(page_references) / sizeof(page_references[0]);
    int page_frames = 3;
    int total_page_faults = fifo(page_references, page_references_size, page_frames);
    printf("Total number of page faults: %d\n", total_page_faults);
    return 0;
}
