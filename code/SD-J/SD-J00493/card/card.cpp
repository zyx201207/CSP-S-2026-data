#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],table[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int cnt=0;
			memset(table,0,sizeof(table));
			for(int k=j;k<=n;k++){
				for(int l=1;l<=cnt;l++){
					if(table[l]==a[k]){
						cnt=l-1;
						break;
					}
				}
				table[++cnt]=a[k];
			}
			for(int k=1;k<=cnt;k++){
				if(table[k]==i){
					ans++;
				}
			}
		}
		cout<<ans<<' ';
	}
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
