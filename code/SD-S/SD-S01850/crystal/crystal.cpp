#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans=1;
ll m,a[N],s[N];
void find(int x){
	int l=1,r=x-1,res=x;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[x]*(1ll*(x-mid))-(s[x-1]-s[mid-1])<=m){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(res!=x){
		ans=max(ans,x-res+1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		find(i);
	}
	printf("%d\n",ans);
	return 0;
}
