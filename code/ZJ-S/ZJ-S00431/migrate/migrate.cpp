#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long c,T,n,d,x[N],dis[N],dp[N],vis[N],jl[N];
vector<long long> t[N];
priority_queue<pair<int,int>,
		vector<pair<int,int>>,
		greater<pair<int,int>>> q;
queue<pair<int,int>> qu;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
//		if(c<=10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						t[i].push_back(j);
					}else break;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)vis[j]=0;
				for(int j=1;j<=n;j++)jl[j]=0;
				qu.push({i,0});
				while(!qu.empty()){
					pair<int,int> l=qu.front();
					
					if(vis[l.first]!=0){
						qu.pop();
						if(jl[l.first]==l.second){
							vis[l.first]++;
						}
						continue;
					}else{
						vis[l.first]++;
					}
					jl[l.first]=l.second;
					for(auto p:t[l.first]){
						qu.push({p,l.second+1});
					}qu.pop();
				}
			
				for(int i=1;i<=n;i++){
					if(vis[i]==2)ans++;
				//	cout<<vis[i]<<' ';
				}
			}
			cout<<ans<<'\n';
		
//      }else if(c>18||c<11){
			
//		}else if(c>=11&&c<=12){
			
//		}else if(c>=23&&c<=14){
			
//		}else{
			
//		}
		
		for(int i=1;i<=n;i++){
			t[i].clear();
		}
	}
	return 0;
}
