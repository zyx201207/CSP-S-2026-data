#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
ll c,t,n,d,x[N];
ll read(){
	ll res=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)^48);
}
ll culA(ll k){
	if(k>=d) return 0;
	ll cnt=(d/k)*2-1;
	return max(0ll,n-cnt);
}
bool check(int u,int v){
	int cnt=0;
	if(x[v]-x[u]<=d) return 0;
	for(int j=u+1;j<v;j++)
		if(x[v]-x[j]<=d && x[j]-x[u]<=d) cnt++;
	if(cnt==0){
		for(int j=u+1;j<v;j++)
			for(int k=j+1;k<v;k++)
				if(x[v]-x[k]<=d && x[k]-x[j]<=d && x[j]-x[u]<=d) cnt++;
	}
	if(cnt==0){
		for(int i=u+1;i<v;i++)
			for(int j=i+1;j<v;j++)
				for(int k=j+1;k<v;k++)
					if(x[v]-x[k]<=d && x[k]-x[j]<=d && x[j]-x[i]<=d && x[i]-x[u]<=d) cnt++;
	}
	if(cnt==2) return 1;
	return 0;
}
ll solBF(){
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++)
			if(check(i,j)) ans++;
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		int isA=0;
		for(int i=1;i<=n;i++)
			x[i]=read();
		if(n<=3){
			putchar('0');
			putchar('\n');
			continue;
		}
		ll k=x[2]-x[1];
		for(int i=2;i<=n;i++)
			if(x[i]-x[i-1]!=k){
				isA=1;
				break;
			}
		if(!isA){
			write(culA(k));
			putchar('\n');
			continue;
		}
		write(solBF());
		putchar('\n');
	}
	return 0;
}
