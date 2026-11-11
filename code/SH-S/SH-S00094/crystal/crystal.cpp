#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],j,x,s,ans,y,z;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	s=1;
	ans=0;
	x=a[n];
	j=n;
	z=m;
	for(int i=n;i>=1;--i){
		y=x-a[i];
		s--;
		z+=s*y;
		while(j>0&&a[i]-a[j]<=z){
			z-=a[i]-a[j];
			s++;
			j--;
		}
		ans=max(s,ans);
		x=a[i];
	}
	cout<<ans;
	return 0;
}
