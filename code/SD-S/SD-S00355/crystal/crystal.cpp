#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n>5000){
		int d=a[2]-a[1];
		if(d>=1){
			int sum=0,i;
			for(i=1;sum*d<m+d;i++){//sum=1+2+3+...+n
				sum+=i;
			}
			cout<<i-1;
		}
		else cout<<n;
	}
	else{
		int ans=-1;
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				int t=(r-l+1)*a[r]-(b[r]-b[l-1]);
				if(t<=m&&t>=0) ans=max(ans,r-l+1);
			}
		}
		cout<<ans;
	}
	return 0;
}
