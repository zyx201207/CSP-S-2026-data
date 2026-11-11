#include<bits/stdc++.h>
using namespace std;
const int N=500010;
const int u=500010;
vector<int> g[u];
int c,n,m,d,q,lav[N],cnt,to,to2,pos,ans,pos2,ans2,ll=100000000,wc;

int vto(int s,int c){
	while(g[s].size()==2){
		c+=g[s][1];
		s=g[s][0];
	}
	return s,c;
}
int uto(int s,int c){
	while(g[s].size()==2){
		c+=g[s][1];
		s=g[s][0];
	}
	return s,c;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>lav[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cnt;
		for(int i=1;i<=cnt;i++){
			int jj,bb,head;
			cin>>jj>>bb;
			g[jj].push_back(head);
			g[jj].push_back(bb);
			head=jj;
		}
	}
	for(int i=1;i<=q;i++){
		ll=100000000;
		int u,v;
		cin>>u>>v;
		ans=lav[u]+lav[v];
		ans2=lav[u]+lav[v];
		to=v;
		to2=u;
		wc=g[to].size();
		for(int i=0;i<wc;i+=2){
			while(to==to2){
				to,ans=vto(g[to][i],ans);
				to2,ans2=uto(g[to2][i],ans2);
			}
			ll=min(ll,ans+ans2-(lav[u]+lav[v])+g[to2][1]+g[to2][3]);
		}
		cout<<ll<<'\n';
	}

	return 0;
}
