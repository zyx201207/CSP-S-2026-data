#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long m,mx,a[500100],t[500100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) t[i]=a[i+1]-a[i];
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1,k=0;bool b=0;
		for(int i=1;i<=n-mid+1;i++){
			for(int j=0;j<mid-1;j++) k+=t[i+j]*(j+1);
			if(k<=m){
				b=1;
				break;
			}
			k=0;
		}
		if(b) mx=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<mx;
	return 0;
}//45分