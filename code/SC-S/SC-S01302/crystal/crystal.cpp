#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500005],s[500005];
long long m,b;
int l,r,ma=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=1;r=2;
	while(r<=n){
		b=(r-l)*a[r]-(s[r-1]-s[l-1]);
		if(b<=m){
			ma=max(ma,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<ma;
	return 0;
}