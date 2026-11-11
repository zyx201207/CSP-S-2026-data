#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
#define ll long long
#define N 500005
ll a[N],s[N],m;int n;
bool ok(int len){
	for(int i=len;i<=n;i++){
		ll cost=a[i]*len-(s[i]-s[i-len]);
		if(cost<=m)return 1; 
	}
	return 0;
}
int main(){
	file();
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=0,r=n,res=l;
	while(l<=r){
		int mid=l+(r-l>>1);
		if(ok(mid))res=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",res);
	return 0;
}
