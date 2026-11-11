#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m,g =1;
	cin >> n >>m;
	vector<int> a(n+5),b(m+5),c(m+5);
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		g = i;
		for(int j = i;j<=n;j++){
			b[a[j]] ++;
			if(b[a[j]]>=2){
				for(int l = g;l<j;l++){
					b[a[l]] --;
				}
				g=j;
			}
		}
		for(int k = 1;k<=m;k++){
			c[k] += b[k];
			b[k]=0;
		}
	}
	for(int i = 1;i<=m;i++){
		cout << c[i] << ' ';
	}
	return 0;
}