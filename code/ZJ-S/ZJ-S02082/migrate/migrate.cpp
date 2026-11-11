#include<bits/stdc++.h>
#define endl '\n'
#define mp make_pair
#define pii pair<int,int>
typedef long long ll;
using namespace std;
int c,t,n,dis[5005],cnt[5005];
ll a[2000005],d,ans;
queue<pii>q;
void solve(){
	ans=0;
	memset(dis,0x3f,sizeof dis);
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		q.push(mp(i,0));
		while(!q.empty()){
			pii tmp=q.front();
			q.pop();
			if(tmp.second>dis[tmp.first])continue;
			dis[tmp.first]=tmp.second;
			if(dis[tmp.first]==tmp.second)cnt[tmp.first]++;
			else cnt[tmp.first]=1;
			for(int j=tmp.first+1;a[j]-a[tmp.first]<=d&&j<=n;j++)q.push(mp(j,tmp.second+1));
		}
		for(int j=i+1;j<=n;j++)ans+=(cnt[j]==2);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
