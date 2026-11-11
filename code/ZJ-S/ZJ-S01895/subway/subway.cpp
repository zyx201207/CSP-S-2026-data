#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int to,w;
};
ll c,n,m,d,q,t[10100],mem[1100][1100];
vector<node> v[10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			v[m+i].push_back({a,b});
			v[a].push_back({m+i,b});
		}
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++)mem[i][j]=0x3f3f3f3f3f3f3f3f;
	}
	
	for(int i=1;i<=m+n;i++){
		
		ll now=i;
		ll s[10100]={0};
		s[i]=1;
		mem[i][i]=0;
		for(int j=1;j<=m+n;j++){
			ll minx=0x3f3f3f3f3f3f3f3f,f;
			for(int k=0;k<v[now].size();k++){
				if(s[v[now][k].to]==0){
					mem[i][v[now][k].to]=min(mem[i][v[now][k].to],mem[i][now]+v[now][k].w);
				}
			}
			for(int k=1;k<=n+m;k++){
				if(s[k]==0&&mem[i][k]<minx){
					minx=mem[i][k];
					f=k;
				}
			}
			s[f]=1;
			now=f;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<mem[x][y]+t[x]+t[y]<<"\n";
	}
	return 0;
}
