#include<bits/stdc++.h>
#define int long long
using namespace std;
struct man{
	int x;
	string s;
}a[200005];
int b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l,ll=0,r,rr=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
		b[i]=b[i-1]+a[i].x;
	}
	if(b[n]%2==1){
		r=b[n]/2+1;
		l=b[n]/2+1;
	}
	else{
		r=b[n]/2;
		l=b[n]/2+1;
	}
	for(int i=1;i<=n;i++){
		if(b[i]>=l-1&&ll==0){
			ll=i;
		}
		if(b[i]>=r-1){
			rr=i;
			break;
		}
	}
	for(int i=1;i<=b[n]/2;i++){

		r++;
		l--;
		if(r>b[rr]){
			rr++;
		}
		if(l<=b[ll-1]){
			ll--;
		}	
		if(a[ll].s!=a[rr].s){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
