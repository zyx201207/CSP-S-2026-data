#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int i=1,j=1,ans=i-j;
	long long  sum=0;
	while(++i<=n){
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m){
			j++;
			sum-=a[i]-a[j-1];
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}