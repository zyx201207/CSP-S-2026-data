#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],b[500005],c[500005],m,s;
int ma=-1e9;
long long ws(long long L,long long R){
	return (R-L)*a[R]-b[R-1]+b[L-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			long long dj=ws(i,mid);
			if(dj<=m)l=mid+1,ans=mid;
			else r=mid-1;
		}
		ma=max(ma,ans-i+1);
	}
	cout<<ma<<' ';
	return 0;
}
/*
store:100(?)
O(nlogn)
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);

wo bu yao wan florr!
thoita,qi dong!

bu shi man fen de hua Zingu jiu shi gay
*/
