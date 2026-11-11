#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
typedef __int128 lll;
//template<typename T> inline void read(T &x){
//	x=0;char ch=gc();
//}
const int N=5e5+5; 
ll n,m,a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ll ans1=0;
	for(int i=1;i<=n;i++){
		ll l=1,r=i,ans=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)ans=mid,r=mid-1;
			else l=mid+1;
		}
		ans1=max(ans1,i-ans+1);
	}
	printf("%lld",ans1);
	return 0;
}
