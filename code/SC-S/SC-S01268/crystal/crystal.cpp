#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],b[1000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	sort(b+1,b+n+1);
	if(b[2]>m){
		cout<<1;
		return 0;
	}
	int x=b[2];
	for(int i=2;i<n;i++){
		x+=i*b[i+1];
		if(x>m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}