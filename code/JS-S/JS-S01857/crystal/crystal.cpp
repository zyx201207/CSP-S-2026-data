#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
const int N=5e5+5;
int n,m,p,a[N],cha[N],ans;
bool flag=1;
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	f(i,1,n-1) {
		cha[i]=a[i+1]-a[i];
		if(cha[i]!=cha[i-1]) flag=0;
	}
	if(flag) {
		int s=0;
		f(i,1,m) {
			s+=i*cha[1];
			if(s>m) {
				cout<<i<<endl;
				return 0;
			}
		}
	}
	f(i,1,n) {
		int j=i-1,total=0;
		for(;j>=1;j--) {
			if(total+(a[i]-a[j])>m) break;
			total+=(a[i]-a[j]);
		}
		ans=max(ans,i-j);
	}
	cout<<ans<<endl;
	return 0;
}
