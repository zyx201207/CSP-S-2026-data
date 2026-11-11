#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int mx=5e5+10;
int n,m,ans=1;
ll a[mx],c[mx],sum[mx]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+c[i];
	}
	for(int i=n;i>1;i--){
		int cnt=0,j=i-1;
		for(j;j>1;j--){
			if(cnt+(sum[i]-sum[j])>m){
				j++;
				break;
			}else if(cnt+(sum[i]-sum[j])==m){
				break;
			}
			cnt+=(sum[i]-sum[j]);
		}
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}