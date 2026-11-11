#include<bits/stdc++.h>
#define ll long long
#define N 200100

using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct node{ll x;bool vis;}a[N];
ll n,m,len,ans,tot,Maxn;bool flag=false;
vector<node>v[N];
bool cmp1(node a,node b){return a.x>b.x;}
bool cmp2(node a,node b){if(a.vis!=b.vis)return a.vis>b.vis;return a.x>b.x;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read(),len=n;
	for(int i=1;i<=n;++i)a[i].x=read(),Maxn=max(Maxn,a[i].x);
	sort(a+1,a+1+n,cmp1);
	for(int i=30;i>=0;--i){
		tot=0;
		for(int j=1;j<=n;++j)a[j].vis=(a[j].x&(1ll<<i)),tot+=a[j].vis;
		if(tot<m)continue;
		sort(a+1,a+1+len,cmp2);
		for(int j=len;j>=1&&len>m;--j)if(!a[j].vis)--len;
		flag=true;
		for(int j=1;j<=m&&flag;++j)if(!a[j].vis)flag=false;
		if(flag)ans+=(1ll<<i);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 2
3 15 12 12
 */
