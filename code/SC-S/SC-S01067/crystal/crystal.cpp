#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],t,qz[1000005];
bool cmp(int q,int h){
	return abs(q-t)<=abs(h-t);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,maxx=0;
		while(l<=r){
			int mid=(r-l)/2+l;
			int t=qz[i-1]-qz[mid-1];
			t=a[i]*(i-mid)-t;
			if(t>m) l=mid+1;
			else{    
				maxx=max(maxx,i-mid+1);
				r=mid-1;
			}
		}
		ans=max(maxx,ans);
	}
	cout<<ans<<'\n';
	return 0;
}