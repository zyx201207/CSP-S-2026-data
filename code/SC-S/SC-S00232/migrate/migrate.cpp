#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll x[5005];
vector<vector<int>> G(5005);
vector<ll> st(5005),Len(5005);//没有确保不成环 没有方法
struct node{
	int idx;ll q;
	bool operator<(const node&a)const{return a.q<q;}
};
void serve(int start){
	priority_queue<node> Q;
	Q.push({start,0});
	Len[start]=0;
	while(!Q.empty()){
		node tmp=Q.top();
		Q.pop();
		if(tmp.q>Len[tmp.idx])continue;
		for(int it:G[tmp.idx]){
			if(Len[it]>Len[tmp.idx]+1){
				Len[it]=Len[tmp.idx]+1;
				st[it]=0;
				Q.push({it,Len[it]});
			}
			else if(Len[it]==Len[tmp.idx]+1)st[it]++;
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;ll d;int ans=0;cin>>n>>d;
		for(int j=1;j<=n;j++){cin>>x[j];G[j].clear();}
		for(int k=1;k<=n;k++){
			for(int j=k+1;j<=n;j++){
				if(x[j]-x[k]<=d){G[k].push_back(j);G[j].push_back(k);}
			}
		}
		for(int k=1;k<=n;k++){
			st.clear();
			fill(Len.begin(),Len.end(),1e18);
			serve(k);
			for(int j=k+1;j<=n;j++){
				if(st[j]==1)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}