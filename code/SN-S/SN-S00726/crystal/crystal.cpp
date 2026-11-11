#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,temp,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	for(long long r=2;r<=n;r++){
		temp+=(a[r]-a[r-1])*(r-l);
		while(temp>m){
			temp-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
