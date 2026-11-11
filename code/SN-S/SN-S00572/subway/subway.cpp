#include <bits/stdc++.h>
using namespace std;
int C,N,M,D,Q;
int W[500010];
vector<int>G[500010],Line[510];
int Cnt[510][510];
bool Book[500010];
void chu(int line){
	Book[line]=1;
	for(auto u:Line[line]){
		for(auto next:G[u]){
			if(next!=line){
				Cnt[next][line]=1;
				Cnt[line][next]=1;
				if(!Book[next])chu(next);
			}
		}
	}
	return;
}
void dij(){
	for(int p=1;p<=N;p++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				Cnt[i][j]=min(Cnt[i][j],Cnt[i][p]+Cnt[p][j]);
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bool t=1;
	long long mt=0;
	cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++)cin>>W[i];
	for(int i=1;i<=N;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;cin>>a>>b;
			mt=b;
			G[a].push_back(i);
			Line[i].push_back(a);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i!=j)Cnt[i][j]=1e9;
		}
	}
	chu(1);
	dij();
	while(Q--){
		long long ans=0;
		int l,r;cin>>l>>r;
		ans+=(W[l]+W[r]+2*mt);
		int t=1e9;
		for(auto beg:G[l]){
			for(auto end:G[r]){
				t=min(t,Cnt[beg][end]);
			}
		}
		long long sum=t;
		ans+=2*mt*sum;
		cout<<ans<<"\n";
	}
	return 0;
}
