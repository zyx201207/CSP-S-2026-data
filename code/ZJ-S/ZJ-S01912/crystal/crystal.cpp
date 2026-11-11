#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll n,m,a[N],ans=-1;
bool f=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=false;
	}	
	if(f==true){
		ll k=a[2]-a[1],sum=0,cnt=1;
		for(ll i=k;i;i+=k){
			if(sum+i>m) break;
			if(sum+i<=m) cnt++,sum+=i;
		}
		printf("%lld",cnt);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll cnt=0,sum=0;
		for(int j=i-1;j>=1;j--)
			if(sum+(a[i]-a[j])<=m) sum+=(a[i]-a[j]),cnt++;
		ans=max(ans,cnt+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
13 134
61 64 18 17 -54 -41 47 83 24 89 -67 -6 -24
*/