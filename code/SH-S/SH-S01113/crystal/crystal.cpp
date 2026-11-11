#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int MAXN=5e5+10;
ll a[MAXN],s[MAXN];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll r=1,ans=0;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-r+1)-(s[i]-s[r-1])>m){
			r++;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
