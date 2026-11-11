#include<bits/stdc++.h>
#define ll long long
#define inl inline
#define reg register
using namespace std;
const int MAXN=5e5+10;
ll n,m;
ll a[MAXN];
ll lt,rt,kt,mt;
ll ans;
inl ll read(){
	ll x=0;bool f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f?x:-x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();	
	sort(a+1,a+n+1);
	lt=rt=1;kt=a[1];
	for(int i=1;i<=n;i++){
		ll wd=rt-lt+1;
		if(mt+wd*(a[i]-kt)<=m){
			mt+=wd*(a[i]-kt);
			rt++;
			kt=a[i];
			ans=max(ans,rt-lt+1);
		}else{
			ll x=0,q=wd;
			for(int j=lt;j<=rt;j++){
				x+=kt-a[j];
				q--;
				if(mt-x+q*(a[i]-kt)<=m){
					mt=mt-x+q*(a[i]-kt);
					lt=j+1;rt++;
					kt=a[i];
					ans=max(ans,rt-lt+1);
					break;
				}
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

