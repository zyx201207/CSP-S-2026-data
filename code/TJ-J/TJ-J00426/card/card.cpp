#include<bits/stdc++.h>
using namespace std;
int n, m, b, c[300005], d[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> d[i];
	}
	for(int j = 0;j<n;j++){
		int l = 1, a[500005] = {0};
		a[1+j] = d[1+j];
		for(int i = 2+j;i<=n;i++){
			b = d[i];
			bool p = true;
			for(int h = 1;h<=l;h++){
				if(a[h] == b) p = false;
				if(!p){
					l--;
					a[h] = 0;
				}
			}
			l++;
			a[l] = b;
		}
		for(int i = 1;i<=l;i++){
			c[a[i]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout << c[i] << " ";
	}
	return 0;
}
