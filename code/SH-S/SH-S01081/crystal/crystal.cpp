#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
const int N=int(5.1e5);
ll a[N+5];
ll s[N+5];
ll sum(int l,int r){
	
	return s[r]-s[l-1];
}
ll calc(int sel,int x){
	return a[x]*(x-sel)-sum(sel,x-1);
}
int search(int x){
	//find the largest y that calc(y,x)<=m
	//returns: largest y
	int l=1,r=x;
	while(l<r){
		int mid=l+(r-l)/2;
		if(calc(mid,x)<=m){
			r=mid;
		}else{//> m
			l=mid+1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll ans=-1;
	for(int i=1;i<=n;i++){
		//chk
		//wang qian lei ji
		ll delta=0;
		int j=i-1;
		//clog<<"T"<<i<<"\n";
//		for(;j>=1;j--){
//			if(delta+a[i]-a[j]>m){
//				break;
//			}
//			delta+=a[i]-a[j];
//			//clog<<j<<" ";
//		}
//		for(;j>=1;j--){
//			if(calc(j,i)>m){
//				break;
//			}
//		}
		//clog<<"search"<<i<<" "<<search(i)<<"\n";
		//clog <<"\n";
		ans=max(ans,(i-(long long)search(i))+1);
	}
	cout<<ans;
}
