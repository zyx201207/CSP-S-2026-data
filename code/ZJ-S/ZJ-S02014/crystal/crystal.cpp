#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ste,ans;
bool flag=true,flag2=true;
bool check(long long x){
	for(long long i=n;i>=x;i--){
		ste=0;
		for(long long j=1;j<x;j++){
			ste+=a[i]-a[i-j];
			if(ste>m){
				ste=0;
				break;
			}
			if(j==x-1){
				return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=false;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag2=false;
		}
	}
	long long lin=0;
	if(flag){
		for(int i=1;i<=n;i++){
			lin+=i;
			if(lin>m){
				ans=i;
				break;
			}
		}
		cout<<ans;
	}
	else if(flag2==true){
		long long dif=a[2]-a[1];
		for(int i=1;i<=n;i++){
			lin+=i*dif;
			if(lin>m){
				ans=i;
				break;
			}
		}
		cout<<ans;
	}
	else if(!flag2&&!flag){
		sort(a+1,a+1+n);
		long long l=1,r=n,mid=(l+r)/2;
		while(l<=r){
			mid=(l+r)/2;
			ste=0;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	return 0;
}