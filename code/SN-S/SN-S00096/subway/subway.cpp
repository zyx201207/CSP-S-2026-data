#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int a[5005][5005],t[5005][5005];
int x[500005],y[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int ans=0;
		ans+=w[x[i]]+w[y[i]];
		int pos=0,poss=0;
		for(int i1=1;i1<=n;i1++){
			for(int j1=1;j1<=k[i];j1++){
				if(a[i1][j1]==x[i]){
					pos=i1;
				}
				if(a[i1][j1]==y[i]){
					poss=i1;
				}
			}
		}
		if(pos==poss){
			for(int j=1;j<=y[i];j++){
				ans+=t[pos][j];
			}
			cout<<ans<<'\n';
		}
		else {
			for(int j=1,i2=1;j<=k[i2]-1;j++,i2++){
				ans+=t[j][j]+t[j][j+1];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
