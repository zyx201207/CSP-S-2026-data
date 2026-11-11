#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
ll a[200005];
ll ans=0;
bool vis[200005];
void dfs(ll pos){
	if(pos<0)return;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if((a[i]>>pos)&1)cnt++;
	}
	if(cnt>=m){
		ans|=(1ll<<pos);
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(!((a[i]>>pos)&1))vis[i]=1;
		}
	}
	dfs(pos-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	dfs(30);
	out(ans);
	return 0;
}