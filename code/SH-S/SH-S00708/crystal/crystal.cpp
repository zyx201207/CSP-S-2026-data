#include<bits/stdc++.h>
using namespace std;
int n,ans,j=1;
long long m,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while(j<i&&a[i]*(i-j+1)-s[i]+s[j-1]>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
