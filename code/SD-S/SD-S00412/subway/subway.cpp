#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=4e5;
struct node{
	int k,a[N],b[N];
}ab[510];
int c,n,m,d,q;
int w[N];
ll mi;
void zhao(int t,int x,ll s){
	if(x==t){
		mi=min(mi,s);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=ab[i].k;j++){
			if(ab[i].a[j]==x&&j>1){
				s+=ab[i].b[j];
				for(int c=1;c<j;c++){
					zhao(t,ab[i].a[c],s+=ab[i].b[c]);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&ab[i].k);
		for(int j=1;j<=ab[i].k;j++){
			scanf("%d%d",&ab[i].a[j],&ab[i].b[j]);
		}
	}
	int x,y;
	for(int t=1;t<=q;t++){
		mi=5e10;
		scanf("%d%d",&x,&y);
		zhao(x,y,0);
		printf("%d\n",mi+w[x]+w[y]);
	}
	return 0;
}
