#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[5000000];
int hand[5000000];
int card[5000000];
int table[50000000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, sum;
	cin >> n >> sum;


	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}
	for (int i = 1; i <= n; i++) {
		int k = 1;
		for (int j = i; j <= n ; j++) {

			hand[k] = card[j];
			k++;

		}
		k--;
		//cout << k << " ";
		int num = 0;
		for (int j = 1; j <= k; j++) {
			table[num + 1] = hand[j];
			num++;
			for (int z = 1; z <= num - 1; z++) {
				//	cout << z << " " << table[num] << " " << table[z] << endl;

				if (table[z] == table[num] ) {
					//	cout << 867;
					table[z] = 0;
					table[z + 1] = 0;
					for (int q = z; q <= num; q++) {
						table[q] = table[q + 1];
					}
					num--;
					for (int q = z; q <= num  ; q++) {
						table[q] = table[q + 1];
					}
					num --;



				}


			}
			//cout << num << "num;";
			//for (int r = 1; r <= num; r++) {
			//	cout << table[r] << " "  ;
			//	}
			//	cout << j << endl;

		}
		for (int j = 1; j <= num; j++) {
			cnt[table[j]]++;
		}

	}
	for (int i = 1; i <= sum; i++) {
		cout << cnt[i] << " ";
	}


	return 0;
}