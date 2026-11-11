#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct Node{
	int ax,ay;
}r[2510];
Node r1[2510];
int c,m,n,d,q,x;
int a[510][N],t[510][N],k[510],x[N],y[N];
int w[N];
long long ans=INT_MAX;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&x);
			t[i][a[i][j]]=x;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
		int cnt=0,cnt1=0;
		long long sum=0;
		sum+=w[x[i]]+w[y[i]];
		for(int j=1;j<=n;j++){
			for(int m=1;m<=k[j];m++){
				if(a[j][m]==x[i]){
					r[cnt+1].ax=j;
					r[cnt+1].ay=m;
					cnt++;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int m=1;m<=k[j];m++){
				if(a[j][m]==y[i]){
					r1[cnt1+1].ax=j;
					r1[cnt1+1].ay=m;
					cnt1++;
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			for(int m=1;m<=cnt1;m++){
				sum+=t[r[j].ax][x[i]]+t[r1[m].ax][y[i]];
			}
		}
	}
	return 0;
}