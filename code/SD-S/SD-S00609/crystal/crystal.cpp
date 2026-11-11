#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[555555],s[555555],ma;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		for(int j=1;j<i;j++){
			if(a[i]*(i-j+1)-s[i]+s[j-1]<=m){
				ma=max(ma,i-j+1);
			}
			
		}
	}
	cout<<ma;
	return 0;
}
