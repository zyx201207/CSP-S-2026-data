#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100],l,r,ans,s[500100];
bool check(int x,int len){
	return (len*a[x]-(s[x-1]-s[x-len-1]))<=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=1,r=n;
	for(int i=1;i<=n;i++){
		int k=0;
		int l=0,r=i-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				k=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,k+1);
	}
	cout<<ans;
	return 0;
}
/*
========================
    L Z 1 2 0 3 0 9 
     luogu.com.cn
========================
*/
