#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000000],p[20005][20005];
struct le{
	int st;
	int left;
}a[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(p,0x1f,sizeof(p));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j].st>>a[j].left;
		}	
		for(int j=1;j<=k;j++)
			for(int x=j+1;x<=k;x++){
				p[a[j].st][a[x].st]=min(a[j].left+a[x].left,p[a[j].st][a[x].st]);
			}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
	int x,t;
	for(int i=1;i<=q;i++){
		cin>>x>>t;
		cout<<p[x][t]+w[x]+w[t]<<endl;
	}
	return 0;
}
