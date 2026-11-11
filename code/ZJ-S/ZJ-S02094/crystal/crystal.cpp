#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500005],pre[500005];

int check_dj(int l,int r,int m){
	int to=a[r]*(r-l+1)-(pre[r]-pre[l-1]);
	return to;
}

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
	}
	int l=1,r=1,ans=1;
	while(1){
		int to=check_dj(l,r,m);
		if(to<=m){
			if(r==n){
				ans=max(ans,r-l+1);
				break;
			}else{
				ans=max(ans,r-l+1);
				r++;
			}
		}else{
			l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
