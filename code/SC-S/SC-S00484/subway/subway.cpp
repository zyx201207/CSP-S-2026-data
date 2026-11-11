#include<bits/stdc++.h>
using namespace std;

unsigned long long ulrd() {
	unsigned long long x=0;char c=' ';
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}

long long lrd() {
	long long x=0,y=1;char c=' ';
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),y=0;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
long long f[501][501];
int w[501];
int n,m,c,d,q;
int *a[5]={&c,&n,&m,&d,&q};
void grd() {
	for(int i=0;i<5;i++)
	*a[i]=ulrd();
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	grd();
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	if(i!=j)f[i][j]=1e9;
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k=ulrd();
		vector<pair<int,long long>>v(k+1);
		for(int j=1;j<=k;j++){
			v[j]={ulrd(),ulrd()};
		}
		for(int a=1;a<=k;a++)
		for(int b=a+1;b<=k;b++)
		f[v[b].first][v[a].first]=f[v[a].first][v[b].first]=min(f[v[a].first][v[b].first],v[b].second+v[a].second);
	}
	
	for(int i=1;i<=m;i++)
	for(int j=i+1;j<=m;j++)
	for(int k=1;k<=m;k++)
	f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x=ulrd(),y=ulrd();
		long long ans=f[x][y]+w[x]+w[y];
		string s=to_string(ans);
		for(auto&i:s)putchar(i);putchar('\n');
	}
	
	
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<f[i][j]<<' ';putchar('\n');}
	return 0;
}