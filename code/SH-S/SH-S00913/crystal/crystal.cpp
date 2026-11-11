#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int r=1,l=1;r<=n;r++){
		s[r]=s[r-1]+a[r];
		while(a[r]*(r-l)-s[r-1]+s[l-1]>m){l++;}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
