#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500005],m,ans[500005]={1};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans[i]=0;
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		int sum=0;
		for(int j=i;j>=0;j--){
			sum+=a[i]-a[j];
			if(sum<=m){
				ans[i]++;
			}
			else{
				break;
			}
		}
	}
	sort(ans,ans+n);
	cout<<ans[n-1];
	return 0;
}
