#include<bits/stdc++.h>
using namespace std;
long long a[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	long long sum=0,ans=1;
	for(long long i=1,j=2;i<=j&&j<=n&&sum>=0;j++){
		while((a[j]-a[j-1])*(j-i)+sum>m){
			sum-=a[j-1]-a[i];
			i++;
		}
		sum+=(a[j]-a[j-1])*(j-i);
		ans=max(ans,j-i+1);
	}
	cout<<ans;
}