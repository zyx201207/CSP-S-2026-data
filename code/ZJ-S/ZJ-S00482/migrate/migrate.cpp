#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int inf=1e18+7;
int c,T,n,d,a[2000005],mn,ans;
void dfs(int s,int t,int res){
	if(res>mn) return ;
	if(s==t){
		if(res==mn) ans++;
		if(res<mn) mn=res,ans=1;
		return ;	
	}
	for(int i=s+1;i<=t;++i){
		if(a[i]-a[s]<=d) dfs(i,t,res+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		int res=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				mn=inf;
				ans=0;
				dfs(i,j,0);
				if(ans==2) res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

