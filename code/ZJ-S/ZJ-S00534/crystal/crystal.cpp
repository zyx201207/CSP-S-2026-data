#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],c[500005],s1=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[i]+c[i-1];
	}
	for(int i=1;i<=n;i++){
		while(a[i]*(i-s1+1)-(c[i]-c[s1-1])>m){
			s1++;
		}
		ans=max(ans,i-s1+1);
	}
	cout<<ans;
	return 0;
}
//14:38 finish
//14:40-15:00 can't do other problems
//16:30 find a bug
//16:37 debug succeed
