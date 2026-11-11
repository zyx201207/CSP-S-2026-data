#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define int long long
#define pb push_back
#define inf 0x3f3f3f3f3f3f3f3f
const int N=2e5+19;
int c,T,n,d,a[N];
int dis[N],cnt[N];
signed main(){
	fre(migrate);
	cin>>c>>T;
	while(T--){
		vector<int> g[N];
		memset(dis,inf,sizeof(dis));
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int l=1;l<n;l++){
			int r=l;
			while(a[r+1]-a[l]<=d&&r<=n){
				r++;
				g[l].pb(r);
			}
		}
		for(int st=1;st<n;st++){
			queue<int> q;
			memset(cnt,0,sizeof(cnt));
			memset(dis,inf,sizeof(dis));
			q.push(st);dis[st]=0;
			while(q.size()){
				int u=q.front();q.pop();
				for(auto v:g[u]){
					//cout<<u<<' '<<v<<endl;
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						cnt[v]=1;
						q.push(v);
					}else if(dis[v]==dis[u]+1){
						cnt[v]++;
						//cout<<'?';
					}
				}
			}
			//if(st==2)cout<<cnt[5]<<'!';
			for(int i=st;i<=n;i++){
				if(cnt[i]==2){
					//cout<<st<<' '<<i<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
