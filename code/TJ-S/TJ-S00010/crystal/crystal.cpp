#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,m,a[500005],b[500005],c,h,x,y,p,o;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-a[i-1]);
	}
	
	for(int i=1;i<=n;i++){
		b[i]+=abs(b[i-1]);
	}
	for(int i=1;i<=n;i++){
		if(b[i]<=m and b[i]>=c){
			c=b[i];
			h=i;
		}
	}
	for(int i=1;i<=h;i++){
		if(b[i]>x){
			x=b[i];
			y=i;
		}
	}
	cout<<h;

	return 0;
}
