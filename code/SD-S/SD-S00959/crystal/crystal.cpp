#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll sum[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	int l=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l+1)-(sum[i]-sum[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
