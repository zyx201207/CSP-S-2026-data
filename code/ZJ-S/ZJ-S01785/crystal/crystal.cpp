#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long num=0;
	long long l=1,r=1;
	for(int i=2;i<=n;i++){
		while(num+(a[i]-a[i-1])*(r-l+1)>m&&l<r) num-=(a[r]-a[l]),l++;
		num+=(a[i]-a[i-1])*(r-l+1);r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
