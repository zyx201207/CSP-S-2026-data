#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],o[1000000],p[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i =1;i <= n;i++){
		cin >> a[i];
	}
	for (int k = 0;k < n;k++){
		int c[n][2],o = 0;
		for (int i = k+1;i <= n;i++){
			for (int j = n;j > i;j--){
				if (a[j] == a[i]){
					i = j;
					break;
				}
			}
			p[a[i]]++;
		}
	}
	for (int i = 1;i <= m;i++) cout << p[i] << " ";
}

