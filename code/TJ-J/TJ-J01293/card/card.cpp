#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main() {
	// N is CardsInput and M is Cardtypes

	freopen("card.in" , "r", stdin );
	freopen("card.out", "w", stdout);

	int          n  , m;
	cin       >> n >> m;
	unsigned int ccnt[m], kards[n];
	memset(ccnt, 0, sizeof(ccnt));

	for (int i = 0; i < n; i++) {
		cin >> kards[i];
	}


	int fristpos[m];

	for (int i = 0; i < n; i++) {
		// Every game
		memset(fristpos, 0x3f, sizeof(fristpos));
		// Put kards
		for (int j = i; j < n; j++) {
			// have kards
			if (fristpos[kards[j] - 1] != INF) {
				for (int k = fristpos[kards[j] - 1]; k < j; k++) {
					fristpos[kards[k] - 1] = INF;
				}
				fristpos[kards[j] - 1] = j;
			} else {
				fristpos[kards[j] - 1] = j;
			}
		}
		
		for (int j = 0; j < m; j++) {
			if (fristpos[j] != INF)
				ccnt[j]++;
		}
	}
	for (int i = 0; i < m; i++) cout << ccnt[i] << ' ';
	
	fclose(stdin );
	fclose(stdout);
	
	return 0;
}
