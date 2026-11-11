#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n,m,a[N],ans;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	if(n<=20){
		ans=0;
		for(int i=0; i<(1ll<<n); i++){
			ll res=INT_MAX,cnt=0;
			for(int j=n; j>=1; j--){
				if((i>>(j-1))&1){
					res&=a[j];
					cnt++;
				}
			}
			if(cnt==m)ans=max(ans,res);
		}
		printf("%lld\n",ans);
		return 0;
	}
	else if(n==m){
		ans=INT_MAX;
		for(int i=1; i<=n; i++){
			ans&=a[i];
		}
		printf("%lld\n",ans);
		return 0;
	}
	else if(m==1){
		sort(a+1,a+n+1);
		printf("%lld\n",a[n]);
		return 0;
	}
	bool f1=0;
	for(int i=1; i<=n; i++){
		bool f2=0;
		for(int j=1; j<=30; j++){
			if((1ll<<j)-1==a[i])f2=1;
			if(f2)break;
		}
		if(!f2)f1=1;
	}
	if(!f1){
		ans=INT_MAX;
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=m; i++)ans&=a[i];
		printf("%lld\n",ans);
		return 0;
	}
	bool f3=0;
	for(int i=1; i<=30; i++){
		if((1<<i)==n)f3=1;
	}
	if(f3){
		for(int i=1; i<=n; i++){
			if(a[i]!=i-1){
				f3=0;
			}
			if(!f3)break;
		}
	}
	if(f3){
		ans=INT_MAX;
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=m; i++)ans&=a[i];
		printf("%lld\n",ans);
		return 0;
	}
	ans=INT_MAX;
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=m; i++)ans&=a[i];
	printf("%lld\n",ans);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
/*
3 2
0 1 2
*/
