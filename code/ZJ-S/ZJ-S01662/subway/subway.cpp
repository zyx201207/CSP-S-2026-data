#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
const int S=5e2+7;
const int Q=1e5+7;
int c,n,m,d,q;
int w[N];
int k[S];
vector<pair<int,int> > s[N];
vector<int> mid;
vector<pair<int,int> > adj[S];
int ans[S][S];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ain,tin;
			cin>>ain>>tin;
			s[ain].push_back(make_pair(i,tin));
			if(s[ain].size()==2)mid.push_back(ain);
		}
	}
	for(int i=0;i<mid.size();i++){
		for(int u=0;u<s[mid[i]].size();u++){
			for(int v=u+1;v<s[mid[i]].size();v++){
				int start=s[mid[i]][u].first;
				int end=s[mid[i]][v].first;
				int times=s[mid[i]][u].second+s[mid[i]][v].second;
				adj[start].push_back(make_pair(end,times));
				adj[end].push_back(make_pair(start,times));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i][j]=1e9;
			if(i==j)ans[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			int x=adj[i][j].first,y=adj[i][j].second;
			ans[i][x]=y;
		}
	}
	for(int c=1;c<=n;c++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||c==i||c==j)continue;
				if(ans[i][c]+ans[c][j]<ans[i][j]){
					ans[i][j]=ans[i][c]+ans[c][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int start,end;
		cin>>start>>end;
		int cnt=w[start]+w[end];
		int minn=1e9;
		for(int u=0;u<s[start].size();u++){
			for(int v=0;v<s[end].size();v++){
				int times=s[start][u].second+s[end][v].second;
				int l=s[start][u].first;
				int r=s[end][v].first;
				times+=ans[l][r];
				minn=min(minn,times);
			}
		}
		cnt+=minn;
		cout<<cnt<<"\n";
	}
	return 0;
}
