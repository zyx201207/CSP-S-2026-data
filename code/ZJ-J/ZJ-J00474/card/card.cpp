#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int l[500010],ll=1;
		for(int j=i;j<=n;j++){
			for(int x=1;x<ll;x++){
				if(l[x]==a[j]){
					ll=x;
				}
			}
			l[ll]=a[j];
			ll++;
		}
		for(int j=1;j<ll;j++){
			c[l[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << c[i] << ' ';
	}
	return 0;
}
