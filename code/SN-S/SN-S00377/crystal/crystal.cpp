//yangzirui xianjiaotongdaxuefushuzhongxue SN-S00377
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MIN;
int a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int k=i,sum=0,ans1=1;
		while(k--){
			sum+=(a[i]-a[k]);
			if(sum<=m){
				ans1++;
			}else{
				break;
			}
		}
		ans=max(ans1,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
