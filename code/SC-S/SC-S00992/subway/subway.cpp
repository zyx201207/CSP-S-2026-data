#include<bits/stdc++.h>
using namespace std;
long long m,n,c,w[500005],d,a[505][100005],t[505][100005],x,y,r,z;
struct node{
	long long a[505],t[505],w;
}a[50005];
struct nodeA{
	long long a[505],t[10],w;
}aa[500005];
void bailan(){
	long long t,tt;
	for(int i=1;i<=m;i++)scanf("%lld",&t);
	for(int i=1;i<=n;i++){
		scanf("%lld",&tt);
		for(int j=1;j<=tt;j++)scanf("%lld",&t);
		for(int j=1;j<=tt;j++)scanf("%lld",&t);
	}
	for(int i=1;i<=r;i++){
		scanf("%lld%lld",&t,&t);
		cout<<"棍木"<<endl; 
	}
}
void solveA(){
	long long xm[10];
	for(int i=1;i<=m;i++)scanf("%lld",&aa[i].w);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		long long t[100005],tt;
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&t[j]);
			aa[t[j]].a[i]=1;
		}
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&tt);
			aa[t[j]].t[i]=tt;
			if(x)xm[i]=min(xm[i],)
		}
	}
	for(int i=1;i<=r;i++){
		scanf("%lld%lld",&x,&y);
		if(aa[x].a[1]!=aa[y].a[1]){
			
		}
		else ans=aa[x].w+aa[y].w+aa[x].t[aa[x]]+aa[y].t[aa[y]];
		cout<<ans<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&m,&n,&d,&q);
	if(c>=20){
		if(n<=2){
			solveA();
			return 0;
		}
		else {
			bailan();
		}
	}
	for(int i=1;i<=m;i++)scanf("%lld",&a[i].w);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		long long t[100005],tt;
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&t[j]);
			a[t[j]].a=i;
		}
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&tt);
			if(c<=15)a[t[j]].t[i]=tt;
			z=tt;
		}
	}
	if(c>=16){
		solveB();
		return 0;
	}
	for(int i=1;i<=r;i++){
		scanf("%lld%lld",&x,&y);
		queue<node> q;
		ans=a[x].w+a[y].w;
		q.push(a[x]);
		if(a[x].a==a[y].a)continue;
		dfs(x);
		cout<<ans<<endl;
	}
	return 0;
} 
/*5 8
-3 -1 2 2 7*/