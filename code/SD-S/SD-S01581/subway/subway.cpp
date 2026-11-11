#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=5e5+5;
int c,n,m,d,q,w[M],x[N],y[N],iq[2*N],k;
ll f[N*2];
vector<int>vc[2*N],wc[2*N];
void spfa(int st){
	queue<int>q;
	memset(f,0x3f,sizeof f);
	memset(iq,0,sizeof iq);
	f[st]=0;
	iq[st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		iq[u]=0;
		for(int i=0;i<vc[u].size();i++){
			int v=vc[u][i],w=wc[u][i];
			if(f[u]+w<f[v]){
				f[v]=f[u]+w;
				if(!iq[v]){
					q.push(v);
					iq[v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			int w,v;
			cin>>v>>w;
			v+=n;
			vc[i].push_back(v);
			wc[i].push_back(w);
			vc[v].push_back(i); 
			wc[v].push_back(w);
		}
		
	}
	/*for(int i=1;i<=n+m;i++){
		for(int j=0;j<vc[i].size();j++){
			cout<<vc[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	for(int i=1;i<=q;i++) {
		cin>>x[i]>>y[i];
		spfa(x[i]+n);
		
		cout<<(f[y[i]+n]+w[x[i]]+w[y[i]])<<'\n';	
	}
	return 0;
}

