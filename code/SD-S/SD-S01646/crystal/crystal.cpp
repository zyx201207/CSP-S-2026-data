#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],b[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);	
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int ans=1,win=1;
	ll sum=0;
	for(int i=2;i<=n;i++){
		sum+=(b[i]*ans);
		ans++;
		while(sum>m){
			ans--;
			sum-=(a[i]-a[i-ans]);		
		}
		win=max(ans,win); 
	}
	printf("%d\n",win);
	return 0;
}
