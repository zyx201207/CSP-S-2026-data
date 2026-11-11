#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=5e5+30;
int n;
ll m,a[N],sum=0,cnt=0,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1;
	cnt=1;
	ans=1;
	for(int i=2;i<=n;i++){
		sum+=cnt*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[l]);
			l++;
		}
		cnt=i-l+1;
		ans=max(ans,cnt); 
	}
	cout<<ans;
	return 0;
}
