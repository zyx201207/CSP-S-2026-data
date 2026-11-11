#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,ans;
int a[maxn];
int qzh[maxn];
int fen(int r){
	int rr=r;
	int l=1,res;
	while(l<=r){
		int mid=l+r>>1;
		if(m>=a[rr]*(rr-mid+1)-(qzh[rr]-qzh[mid-1])) r=mid-1,res=mid;
		else l=mid+1;
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		ans=max(ans,i-fen(i)+1);
	}
	cout<<ans;
	return 0;
} 
