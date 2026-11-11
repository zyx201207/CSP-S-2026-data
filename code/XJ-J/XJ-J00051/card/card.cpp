#include <bits/stdc++.h>
using namespace std;
long long m,n;
bool v[300005];
long long a[300005];
long long b[300005];
long long c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i;j<=n;j++){
			if(v[a[j]] == 0){
				b[j-i+1] = a[j];
				v[b[j-i+1]] = 1;
			}
			else{
				int w = j;
				while(b[w] != a[j]){
					v[b[w]] = 0;
					b[w] = 0;
					w--;
				}
			}
		}
		for(int j = 0;j<=m;j++){
			c[b[j]]++;
		}
		for(int j = 0;j<=m;j++){
			b[j] = 0;
			v[j] = 0;
		}
	}
	c[m]++;
	for(int i=1;i <= m;i++){
		cout << c[i] << " ";
	}
	return 0;
}
