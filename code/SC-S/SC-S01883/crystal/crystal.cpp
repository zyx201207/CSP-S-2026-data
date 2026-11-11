#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	long long l=1,r=1,ans=1;
	while(l<=n&&r<=n){
		if(a[r]*(r-l+1)-s[r]+s[l-1]<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
}