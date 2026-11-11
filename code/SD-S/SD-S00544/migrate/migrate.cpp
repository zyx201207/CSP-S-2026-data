#include<iostream>//T3 O(n2) 40
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];
int s[N],cnt[N];
vector<int>g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
				}
				else break;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s[j]=1e9;
				cnt[j]=0;
			}
			s[i]=0;
			cnt[i]=1;
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:g[u]){
					if(s[v]>s[u]+1){
						s[v]=s[u]+1;
						cnt[v]=cnt[u];
						q.push(v);
					}
					else if(s[v]==s[u]+1) cnt[v]+=cnt[u];
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
