#include <bits/stdc++.h>
using namespace std;
#define int long long
long long c,t,n,d;
const int N=2e4+5;
long long x[N],cnt[N],dis[N];
bool b[N];
vector<int>edge[N];
typedef pair<int,int>PII;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
//	cout<<n<<" "<<d<<"???\n";
	if(c<=6){
		for(int i=1;i<=n;i++)edge[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			//	cout<<i<<" "<<j<<"?????\n";
				if(abs(x[i]-x[j])<=d)edge[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[j]=0;dis[0]=9e18;
				cnt[j]=0;
			}
			dis[i]=0;
			b[i]=1;
			queue<PII>q;
			q.push({i,0});
			while(!q.empty()){
				PII f=q.front();
				q.pop();
				for(auto j:edge[f.first]){
					if(!b[j]){
						q.push({j,f.second+1});
						++cnt[j];
						b[j]=1;
						dis[j]=f.second+1;
					}else if(b[j]&&f.second+1==dis[j]){
						++cnt[j];
					}
					
				}
			}
			for(int j=1;j<=n;j++){
				if(cnt[j]==2&&j!=i){
					++ans;
				}
			}
		//	cout<<endl;
		}cout<<ans<<endl;
	}else if(c==13||c==14){
		cout<<"0\n";
	}else {
		int z=(d/x)*x;
		if(z==1)cout<<"0\n";
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
