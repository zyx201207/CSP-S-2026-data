#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,n,le=0,ri=0,sm,da;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(long long i=1;i<n;i++)
	a[i]=a[i]-a[0];
	a[0]=0;
	for(long long i=1;i<n;i++){
	if(sm<=m){
	da=max(da,(ri-le+1));
	ri=i;
	sm+=(a[i]-a[i-1])*(ri-le);
	}
	else
	while(sm<=m)
	{sm+=a[le];
	sm-=a[ri];
	le+=1;
	}
	ri=i;}
	cout<<da;
	return 0;
} 
