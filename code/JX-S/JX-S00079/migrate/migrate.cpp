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
ll n,d;
ll a[2000005];
ll dfs(ll x,ll pos){
    if(x==pos)return 0;
    ll res=(1ll<<60);
    for(int i=x+1;i<=pos;i++){
        if(a[i]-a[x]<=d){
            res=min(res,dfs(i,pos)+1);
        }else break;
    }
    return res;
}
ll check(ll i,ll j){
    ll res=0,len=dfs(i,j);
    for(int k=i+1;k<=j;k++){
        if(a[k]-a[i]<=d)
        if(len==dfs(k,j)+1){
            res++;
        }
    }
    return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c=read(),t=read();
	while(t--){
        n=read();
        d=read();
        for(int i=1;i<=n;i++)a[i]=read();
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)==2){
                    ans++;
                }
            }
        }
        out(ans);
        putchar('\n');
	}
	return 0;
}
