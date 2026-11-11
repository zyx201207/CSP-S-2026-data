#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1;
	long long ans=1;
	long long num=0;
	for(long long r=2;r<=n;r++){
		while((r-l)*(a[r]-a[r-1])+num>m){
			num=num-a[r-1]+a[l];
			l++;
		}
		if((r-l)*(a[r]-a[r-1])+num<=m){
			num+=(r-l)*(a[r]-a[r-1]);
			ans=max(ans,r-l+1); 
		}
	}
	cout<<ans;
	
	return 0;
}
