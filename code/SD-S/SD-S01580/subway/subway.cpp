#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c,n,m,d,q,w[500005],k,f[1005][1005],x,y,a[500005],t[500005];
long long e[5005][5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>a[j];
			cin>>t[j];
			for(int k=1;k<j;k++){
				e[a[j]][a[k]]=t[j]+t[k];
				e[a[k]][a[j]]=t[j]+t[k];
			}
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		queue<int>p;
		p.push(i);
		f[i][i]=0;
		while(!p.empty()){
			int now=p.front();
			p.pop();
			for(int j=1;j<=m;j++){
				int u=now,v=j;
				if(f[i][v]>e[u][v]+f[i][u]){
					f[i][v]=e[u][v]+f[i][u];
					p.push(v);
				}		
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
