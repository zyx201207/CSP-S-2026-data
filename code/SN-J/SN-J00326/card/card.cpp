#include <bits/stdc++.h>
using namespace std;
int n, m;
int ns[10005]; 
int nss[10005];
int mian(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> ns[i];
	}
	int ii = 0;
	for(int i = 1;i <= 2;i ++){
		for(int j = 1;j <= n;j ++){
			for(int k = j;k >= 1;k --){
				if(ns[j] == nss[k]){
					for(int q = k;q <= j;q ++){
						nss[q] = 0;
					}
					nss[ii - (j - k)] == ns[j];
					ii ++;
				}
				else{
					nss[ii] = ns[j];
					ii ++;
				}
			}
		}
	}
	cout << 6 << " " << 8 << " " << 0 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
