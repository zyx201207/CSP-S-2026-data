#include<bits/stdc++.h>
using namespace std;
int w[500500],startt,endd,da;
bool p[550];
struct T{
	int xl,hf;
};
vector<T>x[550];
vector<int>xlsddt[550];
void _(){
	da+=w[startt]+w[endd];
	queue<int>q,ntx,hf;
	q.push(startt);
	ntx.push(0);
	hf.push(0);
	while(!q.empty()){
		int now=q.front(),nowntx=ntx.front(),nowhf=hf.front();
		q.pop();
		ntx.pop();
		hf.pop();
		if(nowntx==0){
			for(int i=0;i<x[now].size();i++){
				q.push(now);
				ntx.push(x[now][i].xl);
				hf.push(nowhf+x[now][i].hf);
			}
		}
		else{
			if(!p[now]){
				q.push(now);
				ntx.push(0);
				hf.push(nowhf+x[now][nowntx].hf);
			}
			for(int i=0;i<xlsddt[nowntx].size();i++){
				if(xlsddt[nowntx][i]!=now&&!p[xlsddt[nowntx][i]]){
					q.push(xlsddt[nowntx][i]);
					ntx.push(x[now][i].xl);
					hf.push(nowhf);
				}
			}
			p[now]=1;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int zs,u,v;
		cin>>zs;
		while(zs--){
			cin>>u>>v;
			xlsddt[i].push_back(u);
			x[u].push_back({i,v});
		}
	}
	while(q--){
		cin>>startt>>endd;
		_();
	}
	return 0;
}
