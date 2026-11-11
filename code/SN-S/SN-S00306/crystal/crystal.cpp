#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1;
	unsigned long long m;
	scanf("%d %llu",&n,&m);
	//printf("%llu\n",m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=n;i>=2;i--){
		unsigned long long t=m;
		int num=1;
		for (int j=i-1;j>=1;j--){
			if ((unsigned long long)(a[i]-a[j])<=t){
				t-=a[i]-a[j];
				num++;
				continue;
			}
			break;
		}
		if (num>ans){
			ans=num;
		}
	}
	printf("%d",ans);
	return 0;
}
