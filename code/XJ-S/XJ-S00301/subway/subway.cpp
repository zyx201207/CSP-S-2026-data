#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
ll f[N][N];
ll n,m,d,q,i,j,k,l,x,y;
ll v[N],b[N],c[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>n>>n>>m>>q>>q;
	for(i=1;i<=m+5;i++)
	for(j=1;j<=m+5;j++)
	f[i][j]=INT_MAX;
	for(i=1;i<=m;i++)
	cin>>v[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++)
		cin>>b[j]>>c[j];
		for(j=1;j<k;j++)
		for(l=j+1;l<=k;l++)
		f[b[j]][b[l]]=f[b[l]][b[j]]=min(f[b[j]][b[l]],c[j]+c[l]);
	} 
	ll T=100;
	while(T--)
	for(i=1;i<m;i++)
	{
		for(j=i+1;j<=m;j++)
		{
			for(k=1;k<=m;k++){
				if(k==i||k==j)continue;
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
		
			}
		} 
	}
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<v[x]+v[y]+f[x][y]<<endl;
	}
	return 0;
}

