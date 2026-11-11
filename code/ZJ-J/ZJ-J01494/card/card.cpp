#include<bits/stdc++.h>
using namespace std;
int n,m,a[200007],b[200007];
bool f[200007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	for(int i=1; i<=m; i++){
		int ans=0;
		for(int j=1; j<=n; j++){
			for(int k=j; k<=n; k++){
				if(f[a[k]])
					for(int p=b[a[k]]; p<k; p++)
						f[a[p]] = 0;
				f[a[k]] = 1;
				b[a[k]] = k;
			}
			if(f[i])
				ans++;
		}
		cout << ans << ' ';
		for(int j=1; j<=n; j++) f[j] = 0;
	}
	return 0;
}