#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=5e5+5;
int n,ans=1;ll a[N],m;
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);int l=1;ll sum=0;
	for(int r=1;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m&&l<=r){
			sum-=a[r]-a[l];
			l++;
		}ans=max(ans,r-l+1);
	}cout<<ans;
	return 0;
}
