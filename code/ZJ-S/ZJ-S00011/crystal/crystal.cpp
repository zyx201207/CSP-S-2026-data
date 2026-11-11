#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],m;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	long long sum=0;
	int ans=1;
	for(int i=2;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}