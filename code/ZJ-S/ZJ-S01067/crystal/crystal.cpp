#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],qz[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int res=1;
	qz[1]=a[1];
	int l,r,mid;
	for(int i=2;i<=n;i++){
		l=1,r=i-1,mid;
		while(l<r){
			int mid=(l+r)>>1;//mid to i-1
			if(a[i]*(i-mid)-(qz[i-1]-qz[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		if(a[i]*(i-l)-(qz[i-1]-qz[l-1])<=m){
			res=max(res,i-l+1);
		}
		qz[i]=qz[i-1]+a[i];
	}cout<<res;
}
