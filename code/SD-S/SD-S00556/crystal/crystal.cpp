#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int r=1;
	int res=1;
	long long cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		while(r+1<=n&&(a[r+1]-a[r])*(r-i+1)+cnt<=m){
			cnt+=(a[r+1]-a[r])*(r-i+1);
			r++;
			res++;
		} 
		ans=max(ans,res);
		res--;
		cnt-=a[r]-a[i];
	} 
	cout<<ans;
	return 0;
} 
