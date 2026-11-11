#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q[514514],pre[514514],res;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		pre[i]=pre[i-1]+q[i];
	}sort(q+1,q+1+n,cmp);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+q[i];
	for(int i=1;i<=n;i++){
		int l=1,r=n-i+1,ans=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(q[i]*mid-(pre[i+mid-1]-pre[i-1])<=m) ans=mid,l=mid+1;
			else r=mid-1;
		}res=max(res,ans);
	}cout<<res;
	return 0;
}
