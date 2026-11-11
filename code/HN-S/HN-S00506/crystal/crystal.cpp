#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N(5e5+7);
int n,cnt(0);
ll m,a[N];
ll c[N],sum[N];
bool check(int j,int i){
	if(m>=1ll*a[j]*(j-i)-1LL*(sum[j-1]-sum[i-1])){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i(1);i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i(1);i<=n;i++){
		c[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i(1);i<=n;i++){
		int l(i),r(n),ans(0);
		while(l<=r){
			int mid((l+r)>>1);
			if(check(mid,i)){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		cnt=max(cnt,ans-i+1);
	}
	cout<<cnt<<'\n';
	return 0;
}

