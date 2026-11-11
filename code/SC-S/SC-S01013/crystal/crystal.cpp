#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],c[N],s[N];
ll mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		s[i]=c[i]+s[i-1];
	}
	int l=2,r=2,res=c[2],tot=c[2];
	while(r<=n){
		while(res<=m&&r<=n){
			if(r-l+1>mx) mx=r-l+1;
			tot+=c[++r];
			res+=(r-l+1)*c[r];
		}
//		cout<<l<<" "<<r<<" "<<res<<endl;
		while(res>m&&r>l){
			res-=tot;
			tot-=c[l];
			l++;
		}
//		cout<<l<<" "<<r<<" "<<res<<endl;
	}
	cout<<mx+1;
	return 0;
}