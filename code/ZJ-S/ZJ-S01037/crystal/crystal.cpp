#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+29,M=1e12+9;
ll n,m,l,r,ans,sum;
ll a[N],b[N];
bool ft;
bool f(ll l,ll x){
	ll sum1=b[x]-b[l-1];
	ll sum2=a[x]*(x-l+1);
	return sum2-sum1<=m;
}
inline ll read(){
	char x;
	ll sum=0,f=1;
	x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-') f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9'){
		sum=sum*10+x-'0';
		x=getchar();
	}
	return sum*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++) a[i]=read()+M;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(ll i=1;i<n;i++){
		l=i,r=n;
//		cout<<i<<":\n";
		while(true){
//			cout<<l<<" "<<r<<"\n";
			ft=true;
			if(r-l<=3){
				for(ll mid=l;mid<=min(r+2,n);mid++){
					if(!f(i,mid)){
//						cout<<i<<" "<<mid<<"\n";
						sum=mid-i;
						ft=false;
						break;
					}
				}
				ft=false;
			}
			if(!ft) break;
//			cout<<(r+l)/2<<"!\n";
			if(f(i,(l+r)/2)) l=(l+r)/2;
			else r=(l+r)/2;
		}
		ans=max(ans,sum);
//		cout<<sum<<"\n";
	}
	if(f(1,n)){
		ans=n+(m-(n*a[n]-b[n]))/n;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
