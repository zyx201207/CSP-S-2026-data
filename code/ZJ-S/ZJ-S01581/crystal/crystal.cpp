#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500500],s,s2,i2,cs;
signed main(){
  freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s+=a[i];
		while((i-i2)*a[i]-s+s2>m){
			s2+=a[++i2];
		}
		cs=max(cs,i-i2);
	}
	cout<<cs;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/