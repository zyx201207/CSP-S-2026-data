#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
int n;ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);

	int l=1,r=1,ans=0;
	ll sum=0;
	for(;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m)
			sum-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

