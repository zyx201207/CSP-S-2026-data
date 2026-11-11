#include<bits/stdc++.h>
using namespace std;
long long n;
long long m,a[500005],f[500005];
bool check(long long x){
	if(x*a[x]-f[x]<=m){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
  	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
    	f[i]=a[i]+f[i-1];
    	
	}
	long long l=1,r=n,i,mid=0;
	while(l<=r)
	{
		mid=(l+r+1)/2;
		if(check(mid)){
			l=mid+1;
			i=mid;
		}else{
			r=mid-1;
		}
	
	}
	cout<<i;
	return 0;
}//Oct31==Dec25?

