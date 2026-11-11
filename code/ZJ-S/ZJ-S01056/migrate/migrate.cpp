#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,T,n,d;
int x[N];
int cnt,minstep;
void dfs(int from,int to,int now,int step){
	if(step>minstep)return ;
	if(now==to){
		if(step<minstep){
			minstep=step;
			cnt=1;
		}
		else cnt++;
		return ;
	}
	for(int i=now+1;x[now]+d>=x[i]&&i<=to;i++)dfs(from,to,i,step+1);
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==1||c==2){
			int ans=0;
			for(int from=1;from<=n-2;from++){
				for(int to=from+2;to<=n;to++){
					cnt=0;
					minstep=4e18;
					dfs(from,to,from,0);
					if(cnt==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		if(c==11||c==12){
			int l=x[2]-x[1];
			if(l>d/2)cout<<0<<'\n';
			else{
				int res=0;
				for(int k=ceil(1.0*d/l)+1;k<min(x[n]-x[1]+l,2*d)/l;k++)res+=n-k;
				cout<<res<<'\n';
//				d/l<k<2*d/l
//				d<L<2d
			}
		}
	}
	return 0;
}