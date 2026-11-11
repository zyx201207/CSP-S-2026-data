#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans;
ll s[N],m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+n+1);
	int l=1,r=1;
	ll sum=0;
	while(r<=n){
		ans=max(ans,r-l+1);
		r++;
		sum+=(s[r]-s[r-1])*(r-l);
		while(sum>m){
			sum-=s[r]-s[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
