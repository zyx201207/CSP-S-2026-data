#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll m,a[N],ans=1,e,b[N],n,d[205];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	ll r=1,l=0;
	while(r<=n){
		e=a[r]*(r-l)-b[r]+b[l];
		if(e<=m){
			ans=max(ans,r-l);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}