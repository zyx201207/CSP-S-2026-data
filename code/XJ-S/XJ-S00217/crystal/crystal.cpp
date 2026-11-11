#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long b[500005],l,r,zd; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	l=n;r=n;
	while(l>=1&&r>=1){
		if(a[r]*(r-l+1)-(b[r]-b[l-1])<=m){
			zd=max(zd,(r-l+1));
			l--;
		}else{
			r--;
		}
	}
	cout<<zd;
	return 0;
} 
//15:08 easy! jing ran zhe me jian dan
//luogu:Dong_XK
