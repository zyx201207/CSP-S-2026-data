#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int k=1;k<=n;k++){
		cin>>a[k];
	}
	sort(a+1,a+n+1);
	int i=1,j=1,cnt=0,ans=0;
	long long sum=0;
	for(i=1;i<=n;i++){
		sum+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(sum>m){
			sum-=(a[i]-a[j]);
			j++;
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}