#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,jh,x,y;
int w[500001],k[501],at[500001];
int ans=0;
int mp[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			if(at[a]!=0){
				jh=at[a]+t;
			}
			at[a]=t;
			mp[k[i]][a]=k[i];
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=at[x];
		if(mp[x][y]!=1){
			ans+=jh;
		}
		ans+=at[y];
		ans+=w[y];
		cout<<ans<<endl;
	}
	return 0;
} 
