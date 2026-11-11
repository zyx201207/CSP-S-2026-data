#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000006],cnt,mi=1e9+7,ans,anss;
vector<int> g[200006];
void dfs(int x,int y){
	if(x==y){
		if(mi>cnt){
			mi=cnt;
			ans=1;
		}
		else if(cnt==mi){
			ans++;
		}
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		cnt++;
		dfs(g[x][i],y);
		cnt--;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=200000;i++){
			g[i].clear();
			anss=0;
		}
		if(n<=300){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				for(int j=i-1;j>=1;j--){
					if(a[i]-a[j]<=d){
						g[j].push_back(i);
					}
				}
			}
			
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					cnt=0;
					ans=0;
					mi=1e9+7;
					dfs(i,j);
					if(ans==2){
						anss++;
					}
				}
			}
			cout<<anss<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<"\n";
		}
	}
	
	return 0;
} 
