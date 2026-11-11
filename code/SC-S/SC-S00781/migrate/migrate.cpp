#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+9,M=5e3+9;
int c,t,n,d,a[N],cnt[M],dis[M],ans;
vector <int> e[M];
queue <int> q;
void solve1(int x){
	q.push(x);
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	dis[x]=0;
	cnt[x]++;
	while(!q.empty()){
		int nw=q.front();q.pop();
		for(int i:e[nw]){
			if(dis[i]==dis[nw]+1)cnt[i]+=cnt[nw];
			if(dis[i]>dis[nw]+1){
				dis[i]=dis[nw]+1;
				cnt[i]+=cnt[nw];
				q.push(i);
			} 
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=10){
			ans=0;
			for(int i=1;i<=n;i++)e[i].clear();
			for(int i=1,j=1;i<=n;i++){
				while(j<i&&a[i]-a[j]>d)j++;
				for(int p=j;p<i;p++)e[p].push_back(i);
			}
			for(int i=1;i<=n;i++){
				solve1(i);
				for(int j=i+1;j<=n;j++)if(cnt[j]==2)ans++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}