#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],nm,sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=a[n];i++){
		nm=m,sum=0;
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				if(i-a[j]>nm)
					break;
				nm-=i-a[j];
				sum++;
			}
		}
		ans=max(sum,ans);
	}
	printf("%lld",ans);
	return 0;
}
