//王浩澜 西安交通大学附属中学 SN-S00516
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],dis[505][505],x,y,ans,ansi,ansj;
vector<long long> a[500005],t[500005];
long long read(){
	char c;
	long long x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			f=-1;
		if(c==EOF)
			return 0;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			x=read(),y=read();
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
		
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++)
			for(int k=j+1;k<a[i].size();k++){
				dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
				dis[a[i][k]][a[i][j]]=min(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
			}
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<endl;
	
	while(q--){
		ans=0x3f3f3f3f3f3f3f3f;
		x=read(),y=read();
		for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++){
				if(dis[a[x][i]][a[y][j]]+t[x][i]+t[y][j]<ans)
					ansi=a[x][i],ansj=a[y][j];
				ans=min(ans,dis[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
			}
//		cout<<ansi<<" "<<ansj<<" ";
//		printf("%lld\n",ans+w[x]+w[y]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
