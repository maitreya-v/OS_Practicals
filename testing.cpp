#include <iostream>
using namespace std;

int main()
{
    int n=20;

    int page_references[20]={7, 0, 1, 2,
               0, 3, 0, 4, 2, 3, 0, 3, 2, 1,
               2, 0, 1, 7, 0, 1};

    int page_frames = 3;
    int page_faults = 0;
    int frames[page_frames] = {-1, -1, -1}; // initialize frames with -1

    for (int i = 0; i < n; i++) {
        int inframe = 0;

        for (int j = 0; j < page_frames; j++) {
            if (page_references[i] == frames[j]) {
                inframe = 1;
                break;
            }
        }

        if (inframe == 0) {
            int farthest_index = -1;
            int farthest_distance = -1;

            for (int j = 0; j < page_frames; j++) {
                int distance = 0;

                for (int k = i + 1; k < n; k++) {
                    if (frames[j] == page_references[k]) {
                        distance = k - i;
                        break;
                    }
                }

                if (distance == 0) {
                    farthest_index = j;
                    break;
                }

                if (distance > farthest_distance) {
                    farthest_index = j;
                    farthest_distance = distance;
                }
            }

            frames[farthest_index] = page_references[i];
            page_faults++;
        }

        cout << "Frames: ";
        for (int j = 0; j < page_frames; j++) {
            cout << frames[j] << " ";
        }
        cout << endl;
    }

    int hits = n - page_faults;
    cout << "No. of hits = " << hits << endl;
    cout << "No. of misses = " << page_faults << endl;

    return 0;


}
