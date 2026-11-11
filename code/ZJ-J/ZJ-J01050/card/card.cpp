#include<bits/stdc++.h>
using namespace std;
int f[300010],a[500010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(0,sizeof(b),0);
		int u = 0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=u;k++){
				if(b[k]==a[j]) u = k-1;
			}
			b[++u] = a[j];
		}
		for(int j=1;j<=u;j++){
			f[b[j]] ++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}