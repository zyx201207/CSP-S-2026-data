#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],ans,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long tmp=0,mm=m;
		for(int j=n;j>=1;j--){
			if(a[j]<=a[i]){
				int need=a[i]-a[j];
				if(mm-need>=0){
					mm-=need;
					tmp++;
					
				}
			}
		}
		ans=max(tmp,ans);
		while(a[i+1]==a[i])i++;
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
