#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
const int inf=1e18;
int z,res,minn=inf,c,t,n,d,x[M];
void dfs(int t,int xx){
	if(t>minn){
		return;
	}
	if(xx>z){
		return;
	}
	if(xx==z){
		if(t==minn){
			res++;
		}
		else if(t<minn){
			minn=min(minn,t);
			res=1;
		}
		return;
	}
	for(int j=xx+1;j<=n;j++){
		if(x[j]-x[xx]<=d){
			dfs(t+1,j);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				z=j;
				minn=inf;
				res=0;
				dfs(0,i);
				if(res==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
