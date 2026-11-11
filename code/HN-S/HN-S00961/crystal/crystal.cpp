#include<bits/stdc++.h>
using namespace std;
long long m1,m,a[500005];
int n,ans=1,ans1=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(a,0,sizeof(a));
	scanf("%d %lld",&n,&m),m1=m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		for(int j=1;j<=i;j++){
			if(m+a[i-j]-a[i]>=0){
				m+=a[i-j]-a[i];
				ans1++;
			}else{
				break;
			}
		}
		ans=ans<ans1?ans1:ans;
		ans1=1;m=m1;
	}
	printf("%d",ans);
	return 0;
}
