#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,u,ma=1,x;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=1;
	while(r<n){
		r++;
		u+=(a[r]-a[r-1])*(r-l);
		while(u>m){
			u-=a[r]-a[l];
			l++;
		}
		ma=max(ma,r-l+1);
	}
	cout<<ma;
	return 0;
} 
