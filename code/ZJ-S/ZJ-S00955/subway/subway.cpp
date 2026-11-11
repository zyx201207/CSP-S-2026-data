#include<bits/stdc++.h>
using namespace std;
const int delta=500000;
int c,n,m,d,q,tim;
int w[500010];
struct edge{
	int en,num;
};
vector <edge>e[500510];
int vis[500510];
struct po{
	int num,nm;
	bool operator<(const po &ppp)const{
		return num>ppp.num;
	}
};
priority_queue<po> qu;
int dij(int st,int en){
	while(!qu.empty())qu.pop();
	po te2;
	te2.num=0;
	te2.nm=st;
	qu.push(te2);vis[te2.nm]=tim;
	while(1){
		te2=qu.top();qu.pop();
		if(te2.nm==en)return te2.num;
		vis[te2.nm]=tim;
		for(int i=0;i<int(e[te2.nm].size());i++){
			edge te3=e[te2.nm][i];
			if(vis[te3.en]==tim)continue;
			po te4;
			te4.nm=te3.en;te4.num=te3.num+te2.num;
			qu.push(te4);
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		
		for(int j=1;j<=t;j++){
			int aa,bb;
			cin>>aa>>bb;
			edge te1;
			te1.num=bb;te1.en=i+delta;e[aa].push_back(te1);te1.en=aa;e[i+delta].push_back(te1);
		}			
	}
	for(int i=1;i<=q;i++){
		tim=i;
		int ee,ll;
		cin>>ee>>ll;
		cout<<dij(ee,ll)+w[ee]+w[ll]<<"\n";
	}
	return 0;
}