#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],b[N],ans,s,c;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	int l=1,r=1;
	while(r<n){
		c+=b[r];
		s+=b[r]*(r-l+1);
		while(s>m){
			s-=c;
			c-=b[l];
			l++;
		}
		//cout<<l<<" "<<r<<" "<<c<<" "<<s<<endl;
		ans=max(r-l+2,ans);
		r++;
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9
*/

