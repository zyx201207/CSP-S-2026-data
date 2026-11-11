#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[514514];
main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int ans=1;
	int l=1,r=1,sum=0;
	for(;r<n;){
		while(r<n&&sum+(a[r+1]-a[r])*(r-l+1)<=m){
			sum+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		ans=max(ans,r-l+1);
		sum-=a[r]-a[l]; 
		l++;
	}
	cout<<ans<<endl;
} 
//100 pts?
