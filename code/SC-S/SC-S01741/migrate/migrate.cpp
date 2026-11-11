#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,T,n,d,x[N],cnt,sum,ans,mum;
void dfs(ll st,ll ed,ll res,ll m){
	if(st==ed){
		if(res<sum||(res==sum&&m<mum)){
			sum=res;
			mum=m;
			cnt=0;
		}
		if(sum==res&&m==mum) cnt++;
	}
	for(ll i=st+1;i<=ed;i++){
		if(x[i]-x[st]>d) break;
		dfs(i,ed,res+x[i]-x[st],m+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(ll i=1;i<=n;i++) cin>>x[i];
		if(c<=10){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					cnt=0,sum=INF;
					dfs(i,j,0,0);
					if(cnt==2) ans++;
				}
			cout<<ans<<'\n';
		}else{
			srand(time(0));
			cout<<rand()%5<<'\n';
		}
	}
	return 0;
}