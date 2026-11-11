#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	char c=getchar();
	ll l=1,ret=0;
	while(!isdigit(c))l=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*l;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+7;
ll n,m,a[N],l,cnt,num,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	l=1;
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		num=a[i]-a[i-1];
		cnt+=num*(i-l);
		while(cnt>m){
			cnt-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}