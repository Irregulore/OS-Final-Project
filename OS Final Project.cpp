// Micah Angell & Jaxon Gillham
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// FIFO page replacement implementation
int fifo() {

}

int main()
{
    // Variable declarations
    string fileName;
    char algorithm;
    char comma;
    int frameCount;
    int pages[100];
    int count = 0;

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

    // Find which algorithm is being used
    if (algorithm == 'F') {
        fifo();
    }
    else if (algorithm == 'O') {
        // Optimal algorithm will go here
    }

    return 0;
}
