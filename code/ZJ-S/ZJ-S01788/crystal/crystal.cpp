#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;
	cin>>n>>m;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	int l=1,r=1;
	long long cnt=0;
	int ans=0,res=0;
	while(r<=n) {
		r++;cnt+=(r-l)*(a[r]-a[r-1]);
		res++;ans=max(ans,res);
		if(cnt>m) {
			cnt-=a[r]-a[l];
			l++;res--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}