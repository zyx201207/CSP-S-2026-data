#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans;
bool check(int x){
	for(int i=x;i<=n;i++){
		long long t=a[i]-a[i-x];
		if((a[i]-a[i-1])*x-t<=m){
			return 1;
		}
	}
	return 0;
}
void maind(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		maind();
	}
	return 0;
}

