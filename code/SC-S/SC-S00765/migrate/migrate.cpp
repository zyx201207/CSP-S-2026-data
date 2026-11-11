#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+5;
int n,d,x[N];
int ok;int ans=0;
inline void dfs(int i,int cnt,int ed,int last){
	if(x[i]-x[last]>d)return;
	if(i==ed){
		ok++;
		return;
	}
	//1
	if(cnt)dfs(i+1,cnt-1,ed,i);
	//0
	dfs(i+1,cnt,ed,last);
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		bool pd=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],pd&=(i==1||x[i]-x[i-1]==x[2]-x[1]);
		if(pd){
			int l=d/(x[2]-x[1]);
			l=2*l-1;
			if(l<=1)cout<<"0\n";
			else cout<<max(0ll,n-l)<<"\n";
		}
		else{
			ans=0;
			for(int st=1;st<=n-3;st++){
				for(int ed=st+3;ed<=n;ed++){
					ok=0;
					for(int len=1;len<ed-st;len++){
						dfs(st+1,len,ed,st);
						if(ok)break;
					}
					ans+=ok==2;
				}
			}cout<<ans<<"\n";
		}
	}
	return 0;
}
