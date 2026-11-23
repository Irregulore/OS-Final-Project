// Micah Angell & Jaxon Gillham
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// FIFO page replacement implementation
int fifo(int pages[], int pageCount, int frameCount) {

	// variable declarations
    int frames[100];        // array to hold the frames
	int nextToReplace = 0;  // index of the next frame to replace
	int pageFaults = 0;     // # of page faults


    // Initialize all memory frames as empty
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

	// go through each page request
    for (int i = 0; i < pageCount; i++) {

        // assume the page is not found in the frames
        bool pageFound = false;

        // check every frame for the page
        for (int j = 0; j < frameCount; j++) {

            // checks if the page is already in the frame
            if (frames[j] == pages[i]) {
                pageFound = true;
                break;
            }
        }
        // If the page is not found, replace the next frame
        if (pageFound == false) {

			// increase the page fault count
			pageFaults++;

			// replace the next frame with the new page
            frames[nextToReplace] = pages[i];

            // move to the next frame
            nextToReplace++;

            // return to first frame if need be
            if (nextToReplace == frameCount) {
                nextToReplace = 0;
            }
        }


        // display current frame
        cout << "\nPage " << pages[i] << ": ";

        // display all frames
        for (int j = 0; j < frameCount; j++) {

            // empty frames
            if (frames[j] == -1) {
                cout << "- ";
            }
            // filled frames
            else {
                cout << frames[j] << " ";
            }

        }
    }

	return pageFaults;

}

int main()
{
    // Variable declarations
	string fileName;        // name of the input file
	char algorithm;         // character representing the algorithm to use (F for FIFO, O for Optimal)
	char comma;             // character to read the commas in the input file
    int frameCount;         // number of frames
    int pages[100];         // array to hold the page requests
    int count = 0;          // number of page requests

    // Ask the user for the file name
    cout << "Enter file name: ";
    cin >> fileName;

    // Open the input file
    ifstream in_file(fileName + ".txt");

    // Read the algorithm character and frame count
    in_file >> algorithm >> comma >> frameCount;

    // Read each page request separated by commas
    while (in_file >> comma >> pages[count]) {
        count++;
    }

    // Close the input file
    in_file.close();

    // Determine which algorithm is being used
    if (algorithm == 'F') {
        fifo(pages, count, frameCount);
    }
    else if (algorithm == 'O') {
        // Optimal algorithm will go here
    }

    // finish program
    return 0;
}
