#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,n,d;
ll mind=0x3f3f3f3f3f3f3f3f;
ll maxd=0;
ll cnt;
ll coord[2000005];
void dfs(int x,int y,int pre,int now,int dis){
	if(now==y){
		int ldis=dis;
		if(ldis<mind){
			mind=ldis;
			cnt=1;
		}else if(ldis==mind){
			cnt++;
		}
		return;
	}
	if(coord[now+1]-coord[pre]<=d){
		dfs(x,y,pre,now+1,dis-2);
	}
	if(now!=1&&(coord[now+1]-coord[now]<=d)) dfs(x,y,now,now+1,dis+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>coord[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=2+i;j<=n;j++){
				mind=0x3f3f3f3f3f3f3f3f;
				maxd=0;
				cnt=0;
				dfs(i,j,i,i,0);
				if (cnt==2) ans++;
				
			}
		}
		cout<<ans<<'\n';
	}
}
