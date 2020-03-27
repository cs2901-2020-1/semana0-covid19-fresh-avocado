#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

	if (argc > 1) {

		// Get filenames
		string filename1 = argv[1];
		string filename2 = argv[2];

		// Open files and get info about each one
		string line;
		ifstream sequence1(filename1);
		int protein_count1 = 0;
		bool skip_line = true;

		string sequence1_proteins = "";

		while (getline(sequence1, line)) {
			if (!skip_line) {
				sequence1_proteins += line;
			}
			skip_line = false;
		}

		// Now we have all sequence1 proteins in the array
		// let's do the same for sequence2
		
		ifstream sequence2(filename2);
		skip_line = true;

		string sequence2_proteins = "";

		cout << "Printing lines:\n";
		while (getline(sequence2, line)) {
			if (!skip_line) {
				sequence2_proteins += line;
			}
			skip_line = false;
		}

		cout << filename1 << " protein count: " << sequence1_proteins.size() << endl;
		cout << filename2 << " protein count: " << sequence2_proteins.size() << endl;

		// Now let's compare both arrays and count the matches and mismatches
		
		int matches = 0;
	
		int count = min(sequence1_proteins.size(), sequence2_proteins.size());

		for (int j = 0; j < count; ++j) {
			if (sequence1_proteins[j] == sequence2_proteins[j])
				++matches;
		}

		int diff = max(sequence1_proteins.size(), sequence2_proteins.size()) - count;
		int misses = count - matches;
		float percentage_matches = ((float)matches/(float)count)*100.0;
		float percentage_misses = ((float)misses/(float)count)*100.0;

		cout << "Results:" << endl;
		cout << filename1 << " has " << diff << " proteins more than " << filename2 << ". These were obviously not compared and were not counted as mismatches." << endl;
		cout << "There are " << matches << " proteins that matched out of " << count << " compared (" << percentage_matches << "%)." << endl;
		cout << "There are " << misses << " proteins that didn't match (mismatches) out of " << count << " compared (" << percentage_misses << "%)." << endl;

	} else {
		cout << "Need to filenames as input." << endl;
	}

}
