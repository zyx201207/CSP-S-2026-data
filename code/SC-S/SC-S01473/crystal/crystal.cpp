#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500007];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1,j=1;j<n;j++){
		while(sum>m){
			sum-=a[j]-a[i];
			i++;
		}
		ans=max(ans,j-i+1);
		sum+=(a[j+1]-a[j])*(j-i+1);
	}
	cout<<ans<<"\n";
	return 0;
}