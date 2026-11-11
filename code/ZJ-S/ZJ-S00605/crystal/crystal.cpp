#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],s[500010];
bool sbsa=1;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>16 and m>1000) {
		s[0]=0,s[1]=0;
		for(int i=2; i<=n; i++) s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
		for(int i=n; i>=1; i--) {
			if(m>=s[i]) {
				cout<<i<<endl;
				return 0;
			}
		}
	}
	int cha=a[2]-a[1];
	for(int i=3; i<=n; i++) {
		if(a[i]-a[i-1]!=cha) {
			sbsa=0;
		}
	}
	if(sbsa==1) {
		for(int i=n; i>=1; i--) {
			if(m>=(i*(i-1))/2*cha) {
				cout<<i<<endl;
				return 0;
			}
		}
	}
	int ans=-1e9;
	for(int i=1; i<=n; i++) {
		int das=1,ke=m;
		for(int j=1; j<i; j++) {
			s[j]=a[i]-a[j];
		}
		for(int k=i+1; k<=n; k++) {
			if(a[k]==a[i]) das++;
		}
		for(int x=i-1; x>0; x--) {
			if(s[x]<=ke) {
				das++;
				ke-=s[x];
			}
			s[x]=0;
		}
		ans=max(ans,das);
	}
	cout<<ans<<endl;
	return 0;
}
