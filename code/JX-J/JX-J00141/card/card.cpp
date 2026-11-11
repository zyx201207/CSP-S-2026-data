#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x&(-x))
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void out(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)out(x/10),putchar((x%10)+'0');
	else putchar(x+'0');
}
ll n,m;
ll a[500005];
ll d[500005];
ll last[300005];
ll ans[300005];
struct node{
	ll l,r;
}e[500005];
bool cmp(node x,node y){
	return x.l<y.l;
}
ll tot=0;
ll get(ll x){
	ll res=0;
	for(;x;x-=lowbit(x))res+=d[x];
	return res;
}
void change(ll x,ll k){
	for(;x<=n;x+=lowbit(x))d[x]+=k;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(last[a[i]]!=0){
			++tot;
			e[tot].l=last[a[i]];
			e[tot].r=i;
		}
		last[a[i]]=i;
	}
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		ll k=e[i].l+get(e[i].l);
		change(e[i].l,-k);
		change(e[i].r,k);
	}
	for(int i=1;i<=n;i++)change(i,1);
	for(int i=1;i<=n;i++)ans[a[i]]+=get(i);
	for(int i=1;i<=m;i++)out(ans[i]),putchar(' ');
	return 0;
}