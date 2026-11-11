#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum=0,l=1,r,ans=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int r=1;r<=n;r++){
		sum+=a[r];
		while(a[r]*(r-l+1)-sum>m){
			sum-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);	
	}	
	cout<<ans;
}
