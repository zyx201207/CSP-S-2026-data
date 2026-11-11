#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],pre[N],maxx[N];
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		maxx[i]=max(maxx[i-1],a[i]);
	}
	int ans=0;
	for(int l=1,r=1;r<=n;r++){
		while(maxx[r]*(r-l+1)-pre[r]+pre[l-1]>m)
			l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

