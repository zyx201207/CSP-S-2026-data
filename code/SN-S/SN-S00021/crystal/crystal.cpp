#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5e6+10;
ll n,m,ans,w;
ll c[MAXN];
ll read(){
	char x;
	ll f=1,d=0;
	x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9'){
		d=d*10+(x-'0');
		x=getchar();
	}
	return d*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read(); 
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	sort(c+1,c+1+n);
	ll i=1,j=1;
	while(i<=n&&j<=n){
		w+=(i-j)*(c[i]-c[i-1]);
		while(w>m){
			w-=c[i]-c[j];
			j++;
		}
		ans=max(ans,i-j+1);
		i++;
	}
	printf("%lld",ans);
	return 0;
}
