#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+5;
int n;
long long m;
long long a[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,less<long long>());
	int l=n,r=n;
	long long cntVal=m;
	long long cntTgt=a[n];
	int ans=1; //?
	while(r>1) {
		while(l>1&&cntVal-(a[r]-a[l])>=0) l--,cntVal-=a[r]-a[l];
		ans=max(ans,r-l+1);
		cntTgt = a[r];
		cntVal+=(a[r]-a[r-1])*(r-l);
		r--;
	}
	cout<<ans<<endl;
	
	return 0;
}
