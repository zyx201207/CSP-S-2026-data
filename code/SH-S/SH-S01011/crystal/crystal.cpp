#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int T=1,n,m,a[N],id,mx=-1,cnt,aa,bb,d,wem[N];
bool cmp(int x,int y) {
	return x>y;
}
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) aa=1;
		if(i>=3&&a[i]-a[i-1]!=d) bb=1;
		d=a[i]-a[i-1];
	}
	if(n<=5000) {
		sort(a+1,a+1+n,cmp);
		for(int i=1; i<=n; i++) {
			int j=i+1,sum=0,cnt=1;
			while(j<=n) {
				sum+=a[i]-a[j];
				if(sum>m) break;
				cnt++;
				j++;
			}
			int k=i-1;
			while(k>=1&&a[k]==a[i]) {
				k--;
				cnt++;
			}
			mx=max(mx,cnt);
		}
		cout<<mx;
	} else if(!aa) {
		for(int i=n; i>=1; i--) {
			if(m-(a[n]-a[i])<0) break;
			m-=(a[n]-a[i]);
			cnt++;
		}
		cout<<cnt;
	} else if(!bb){
		if(a[2]-a[1]>=0) {
			for(int i=n; i>=1; i--) {
				if(m-(a[n]-a[i])<0) break;
				m-=(a[n]-a[i]);
				cnt++;
			}
			cout<<cnt;
		} else {
			for(int i=1; i<=n; i++) {
				if(m-(a[1]-a[i])<0) break;
				m-=(a[1]-a[i]);
				cnt++;
			}
			cout<<cnt;
		}
	}else{
		int sum=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) wem[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++) sum+=a[n]-a[i];
		for(int i=n;i>=1;i--){
//			cout<<sum<<"\n";
			if(sum<=m) {
				cnt=i;
				break;
			}
			sum-=wem[i]*(i-1);
		} 
		cout<<cnt;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cin>>T;
	while(T--) solve();
	return 0;
}
