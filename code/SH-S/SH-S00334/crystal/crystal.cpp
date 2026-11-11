#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	long long l=1,r=1,ans=0;
	while(r<=n){
		long long len=r-l+1;
		if(a[r]*len<=s[r]-s[l-1]+m){
			ans=max(ans,len);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
} 
