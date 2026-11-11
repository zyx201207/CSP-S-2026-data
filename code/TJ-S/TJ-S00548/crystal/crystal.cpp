#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt,maxx=-1,l=1,r=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cnt=a[1];
	while(r<=n){
		int tgt=a[r]*(r-l+1);
		if(tgt-cnt<=m){
			maxx=max(maxx,r-l+1);
			r++;
			cnt+=a[r];
		}else{
			cnt-=a[l];
			l++;
		}
	}
	cout<<maxx;
	return 0;
} 
