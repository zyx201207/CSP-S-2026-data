#include<bits/stdc++.h>
using namespace std;
long long a[500010],org[500010];
long long m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=2,mx=0;
	for(int i=2;i<=n;i++){
		org[i]=a[i]-a[i-1];
		while(ans>m-org[i]*(i-l+1)){
			int j=1;
			ans-=a[i-j]-a[l-1];
			mx=max(mx,i-l+1);
			l++;
			j++;
		}
		if(ans<=m-org[i]*(i-l+1)){
			ans+=org[i]*(i-l+1);
		}
	}
	mx=max(mx,n-l+2);
	printf("%d",mx);
	return 0;
}
