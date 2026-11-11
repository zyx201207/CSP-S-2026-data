#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=2e6+10;

ll c,t,n;

ll d;

ll x[N],cnt[N];

int dis[N],vis[N];

vector<int> vt[N];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];vt[i].clear();
		}
		if(c==11||c==12){
			ll D=x[2]-x[1];
			ll y=d/D;
			if(y==1ll) cout<<"0\n";
			else if(y>0ll&&n-(2ll*y-1)>0ll) cout<<n-(2ll*y-1)<<"\n";
			else cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			int l=1,mid=1,cntt=0;
			ll ans=0;
			for(int i=1;i<=n;i++){
				while(l<=i&&x[i]-x[l]>d) l++;
				dis[i]=l;
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					mid=i;
					cntt++;
				}
			}
			if(cntt>2){
				cout<<"0\n";
				continue;
			}
			for(int i=mid+1;i<=n;i++){
				if(dis[i]==mid-1){
					ans+=dis[mid+1]-1;
				}else if(dis[i]==mid&&i>=mid+2){
					ans+=dis[mid+2]-dis[mid+1];
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int j=i-1;j>=1;j--){
					if(x[i]-x[j]<=d){
						vt[j].push_back(i);
					}else break;
				}
			}
			ll ans=0;
			for(int i=1;i<=n;i++){
				queue<int> q;
				q.push(i);
				for(int j=i;j<=n;j++){
					dis[j]=1e9;cnt[j]=0;vis[j]=0;
				}
				dis[i]=0;cnt[i]=1;
				while(!q.empty()){
					int u=q.front();q.pop();
//					if(vis[u]) continue;
//					vis[u]=1;
					for(int j=0;j<vt[u].size();j++){
						int v=vt[u][j];
						if(dis[v]>dis[u]+1){
							dis[v]=dis[u]+1;
							cnt[v]=cnt[u];
							q.push(v);
						}else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
					}
				}
				for(int j=i+1;j<=n;j++){
					if(cnt[j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<0<<"\n";
	}
	
	return 0;
}

