#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],sum,ans,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+a[i];
	} 
	ll r=1,l=1;
	while(l<=r){
		while(r<=n&&(r-l+1)*a[r]-sum<=m){//移动r 
			sum+=a[r];
			r++;
		}
		ans=max(ans,r-l+1);//更新最大值 
//		cout<<r-l+1<<' '<<l<<' '<<r<<'\n';
		l++;//(枚举l) 
		sum-=a[l]; 
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
//我咋只会第一题 TOT/kel
