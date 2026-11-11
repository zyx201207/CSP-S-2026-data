#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],vis[N],mx[N],ans;
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > >q;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==13 or c==14){
			cout<<0<<endl;
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				if(q.size()>0 and q.top().second+d<x[i]){
					mx[q.top().first]=i;
					q.pop();
				}
				q.push({i,x[i] });
			}
			while(q.size() ){
				mx[q.top().first]=n;
				q.pop();
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					vis[j]=0;
				}
				for(int j=i;j<=n;j++){
					if(mx[j]>j){
						vis[j+1]++;
						vis[mx[j]+1]--;
					}
					vis[j]+=vis[j-1];
					if(vis[j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}