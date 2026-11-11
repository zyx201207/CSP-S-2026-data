#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long sum = 0;
	int ans = 1;
	for(int i=2,ptr=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-ptr);
		while(sum>m) sum-=a[i]-a[ptr],ptr++;
		ans = max(ans,i-ptr+1);
	}
	cout<<ans<<'\n';
	return 0;
}
