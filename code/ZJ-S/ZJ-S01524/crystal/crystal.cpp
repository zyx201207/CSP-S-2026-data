#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0; i<n; ++i) {
		cin>>a[i];
	}
	sort(a,a+n);
	long long cnt=0,l=0,ans=0,mid=0;
	for(int i=0; i<n; ++i) {
		cnt+=(a[i]-a[i-1])*(i-l);
		if((i-l+1)%2==0) {
			++mid;
		}
		while(cnt>m){	
			cnt-=(a[i]-a[l]);
			++l;			
			if((i-l+1)%2==0){
				++mid;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
