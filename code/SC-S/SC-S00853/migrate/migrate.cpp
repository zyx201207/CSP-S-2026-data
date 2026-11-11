#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000006];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(m>=n){
			cout<<0<<'\n';
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if((a[j]-a[i])%m!=m-1||(a[j]-a[i])<m){
					continue;
				}
				int maxn=-1;
				for(int k=i;k<j;++k){
					maxn=max(maxn,a[k+1]-a[k]);
				}
				if(maxn<=m){
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
