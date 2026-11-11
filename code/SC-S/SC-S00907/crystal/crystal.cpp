#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[500005],b[500005];
int t=0;
int max1=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		t=0;
		if(i+1-max1<=0)
			break;
		for(int j=i;j>=1;j--){
			t=t+a[i]-a[j];
			if(t>m){
				max1=max(i-j,max1);
				break;
			}
			else
				max1=max(i-j+1,max1);
		}
		
		
	} 
	printf("%lld",max1);
	return 0;
}