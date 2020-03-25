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

		while (getline(sequence1, line))
			for (char c : line)
				++protein_count1;

		char sequence1_proteins[protein_count1];

		int i = 0;
		while (getline(sequence1, line)) {
			for (char c : line) {
				sequence1_proteins[i] = c;
				++i;
			}
		}

		// Now we have all sequence1 proteins in the array
		// let's do the same for sequence2
		
		ifstream sequence2(filename2);
		int protein_count2 = 0;

		while (getline(sequence2, line))
			for (char c : line)
				++protein_count2;

		char sequence2_proteins[protein_count2];

		i = 0;
		while (getline(sequence2, line)) {
			for (char c : line) {
				sequence2_proteins[i] = c;
				++i;
			}
		}

		cout << filename1 << " protein count: " << protein_count1 << endl;
		cout << filename2 << " protein count: " << protein_count2 << endl;

		// Now let's compare both arrays and count the matches and mismatches
		
		int matches = 0;

		if (protein_count1 > protein_count2) {

			for (int j = 0; j < protein_count2; ++j) {
				if (sequence1_proteins[j] == sequence2_proteins[j]) {
					++matches;
				}	
			}

			int diff = protein_count1 - protein_count2;
			int misses = protein_count2 - matches;
			float percentage_matches = ((float)matches/(float)protein_count2)*100;
			float percentage_misses = ((float)misses/(float)protein_count2)*100;

			cout << "Results:" << endl;
			cout << filename1 << " has " << diff << " proteins more than " << filename2 << ". These were obviously not compared and were not counted as mismatches." << endl;
			cout << "There are " << matches << " proteins that matched out of " << protein_count2 << " compared (" << percentage_matches << "%)." << endl;
			cout << "There are " << misses << " proteins that didn't match (mismatches) out of " << protein_count2 << " compared (" << percentage_misses << "%)." << endl;

		} else if (protein_count1 < protein_count2) {
			for (int j = 0; j < protein_count1; ++j) {
				if (sequence1_proteins[j] == sequence2_proteins[j]) {
					++matches;
				}	
			}

			int diff = protein_count2 - protein_count1;
			int misses = protein_count1 - matches;
			float percentage_matches = ((float)matches/(float)protein_count1)*100;
			float percentage_misses = ((float)misses/(float)protein_count1)*100;

			cout << "Results:" << endl;
			cout << filename2 << " has " << diff << " proteins more than " << filename1 << ". These were obviously not compared and were not counted as mismatches." << endl;
			cout << "There are " << matches << " proteins that matched out of " << protein_count1 << " compared (" << percentage_matches << "%)." << endl;
			cout << "There are " << misses << " proteins that didn't match (mismatches) out of " << protein_count1 << " compared (" << percentage_misses << "%)." << endl;

		} else { // tienen el mismo numero de proteinas
			for (int j = 0; j < protein_count1; ++j) {
				if (sequence1_proteins[j] == sequence2_proteins[j]) {
					++matches;
				}	
			}

			int misses = protein_count1 - matches;

			cout << "Results:" << endl;
			cout << "There are " << matches << " proteins that matched out of " << protein_count1 << " compared." << endl;
			cout << "There are " << misses << " proteins that didn't match (mismatches) out of " << protein_count1 << " compared." << endl;

		}	

	} else {
		cout << "Need to filenames as input." << endl;
	}

}
