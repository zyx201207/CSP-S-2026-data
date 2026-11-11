#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],l;
unsigned long long cnt,sum,ans,d[N];
inline ll read(){
	ll k=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){k=k*10+(c^48);c=getchar();}
	return k*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	l=1;ans=1;cnt=1;
	for(int i=2;i<=n;i++){
		sum+=d[i]*cnt;
		cnt++;
		while(sum>m){
			sum-=(a[i]-a[l]);
			cnt--;
			l++;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
