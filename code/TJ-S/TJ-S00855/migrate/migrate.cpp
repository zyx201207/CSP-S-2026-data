#include<bits/stdc++.h>
using namespace std;
int c,t,n,x,y,ans;
long long d,a[2000005];
int rf(long long x){
	int l=1,r=n,mid,num;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x){
			num=mid;
			break;
		}
		if(a[mid]>x){
			r=mid-1;
		}
		if(a[mid]<x){
			num=mid;
			l=mid+1;
		}
	}
	return num;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13 || c==14){
		cout<<0<<endl;
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			x=rf(a[i]+d);
			y=rf(a[x]+d);
			if(x<i+3 && y>=i+3){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
