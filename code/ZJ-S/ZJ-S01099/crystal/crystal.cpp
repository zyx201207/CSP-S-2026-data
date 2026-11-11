#include <bits/stdc++.h>
using namespace std;
long long n,m,i,t,w,ma,a[500010],j;
bool check(){
	long long gc=a[2]-a[1],i;
	for(i=2;i<=n;i++)
		if(a[i]-a[i-1]!=gc) return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1) cout<<1;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(check()){
		long long gc=a[2]-a[1];
		for(i=0;i<n;i++)
			if(i*gc<=m) m-=i*gc;
			else break;
		i--;
		cout<<i+1;
		return 0;
	}
	for(i=1;i<=n;i++){
		long long mm=m;
		for(j=i-1;j>=1;j--)
			if(abs(a[i]-a[j])<=mm){
				mm=mm-abs(a[i]-a[j]);
			}else break;
		ma=max(ma,i-j);
	}
	cout<<ma;
	return 0;
}
/*
pts=75
ÆÀ²â»ú±£ÓÓÎÒ 
*/
