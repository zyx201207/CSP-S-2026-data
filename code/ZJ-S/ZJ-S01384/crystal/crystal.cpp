#include<bits/stdc++.h>
using namespace std;
long long n,m,l=1,r=1,ans=1,sum1,sum2=1,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		sum1+=sum2*(a[i]-a[i-1]);
		r++;
		sum2++;
		if(sum1>m){
			while(sum1>m){
				sum1-=(a[i]-a[l]);
				l++;
				sum2--;
			}
		}
		ans=max(ans,sum2);
	}
	cout<<ans;
	return 0;
}