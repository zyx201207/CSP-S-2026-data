#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=5e5+1;
int n,ans=1;
ll m,a[maxn];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;
	ll s=0;
	for(int i=2;i<=n;i++) {
		s+=(i-j)*(a[i]-a[i-1]);
		while(s>m) {
			s-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
