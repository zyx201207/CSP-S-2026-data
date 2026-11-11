#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],qz[N],da;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	int l=1,r=1;
	while(r<=n){
		int hf=(r-l)*a[r]-qz[r-1]+qz[l-1];
		while(hf>m){
			l++;
			hf=(r-l)+a[r]-qz[r-1]+qz[l-1];
		}
		da=max(da,r-l+1);
		r++;
	}
	cout<<da;
	return 0;
}
