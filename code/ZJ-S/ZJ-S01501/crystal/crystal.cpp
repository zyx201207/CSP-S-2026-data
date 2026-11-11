#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int check(int x){
	int t=0,res=0;
	for(int h=1;h<=x;h++){
		res+=(a[x]-a[h]);
	}
	//cout<<x<<'\n';
	//cout<<"    "<<res<<'\n';
	if(res<=m)return 1;
	for(int h=2;h<=(n-x+1);h++){
		t=h+x-1;
		res=res-(a[t-1]-a[h-1])+x*(a[t]-a[t-1]);
		//cout<<"    "<<res<<'\n';
		if(res<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    int l=1,r=n,ans=0;
    while(l<r){
    	int mid=(l+r)>>1;
    	if(check(mid))
    	  l=mid+1,ans=mid;else
    	  r=mid;
	}
	cout<<ans;
}
