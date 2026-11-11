#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll sum=0;
	int res=1;
	for(int r=1,l=1;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m) sum-=a[r]-a[l],l++;
		res=max(res,r-l+1);
//		cout<<l<<" "<<r<<endl;
	}
	printf("%d",res);
	return 0;
}
