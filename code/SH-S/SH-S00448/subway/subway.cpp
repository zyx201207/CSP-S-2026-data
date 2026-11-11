#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,N,M,D,Q,w[500005],k[505],floyd[1005][1005],Ans;
vector<pair<int,int> >st[500005];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++){
		cin>>w[i];
	}
	for(int i=1;i<=N;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int t,v;cin>>t>>v;
			st[t].push_back({i,v});
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			floyd[i][j]=1e18;
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=0;j<st[i].size();j++){
			int s1=st[i][j].first,v1=st[i][j].second;
			for(int k=j+1;k<st[i].size();k++){
				int s2=st[i][k].first,v2=st[i][k].second;
				floyd[s1][s2]=floyd[s2][s1]=min(floyd[s1][s2],v1+v2);
			}
		}
	}
	for(int i=1;i<=N;i++){
		floyd[i][i]=0;
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		Ans=1e18;
		for(int i=0;i<st[x].size();i++){
			for(int j=0;j<st[y].size();j++){
				Ans=min(Ans,floyd[st[x][i].first][st[y][j].first]+w[x]+w[y]+st[x][i].second+st[y][j].second);
			}
		}
		cout<<Ans<<endl;
	}
	return 0;
} 
