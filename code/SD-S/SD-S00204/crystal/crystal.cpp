#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	int ans=0;
	int cnt=0;
	while(r<n){
		r++;
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++; 
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

