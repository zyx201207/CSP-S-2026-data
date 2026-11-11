#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500010];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0,sum=0,mn=0;
	for(int i=1;i<=n;i++){
		mn+=(a[i]-a[i-1])*sum;
		while(mn>m){
			mn-=(a[i]-a[i-sum]);
			sum--;
		}
		sum++;
		ans=max(ans,sum);
	} 
	cout<<ans<<" ";
	return 0;
}

