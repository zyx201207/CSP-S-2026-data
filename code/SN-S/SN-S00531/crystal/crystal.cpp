//SN-S00531 张之奇 西安市铁一中学
#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
int n;
long long m,a[maxn],sum[maxn]; 

void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	int ans=0;
	for (int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while (l<=r){
			int mid=((l+r)>>1);
			if (a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)	r=mid-1,res=mid;
			else	l=mid+1; 
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int T;for (cin>>T;T--;)
	solve();
	return 0;
} 
