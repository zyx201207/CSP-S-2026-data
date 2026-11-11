#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],ans;
void find(){
	for(long long int i=0;i<n;i++){
		long long int left=m;
		for(long long int j=i;j>=0;j--){
			left-=(a[i]-a[j]);
			if(left<0)break;
			ans=max(ans,i-j+1);
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	find();
	cout<<ans;
	return 0;
}
