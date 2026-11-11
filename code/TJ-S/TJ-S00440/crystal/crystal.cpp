#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+1+n);
	ll l=1,r=1,num=1,sum=m+a[1];
	while(r<=n and l<=r){
		while((num+1)*a[r+1]>sum+a[r+1])
			num--,sum-=a[l],l++;
		if((num+1)*a[r+1]<=sum+a[r+1])
			num++,sum+=a[r+1],r++,mx=max(mx,num);
		if(r<=n and l<=r)mx=max(mx,num);
	}printf("%lld",mx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

