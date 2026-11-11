#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010],x,y;
vector<pair<int,int> >v[500010];
long long read(){
	long long s=0,b=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s*b;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			a[i][j]=read(),t[i][j]=read();
		}
	}
	while(q--){
		x=read(),y=read();
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}
