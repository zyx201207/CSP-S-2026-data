//刘子墨SN-J00731西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
struct P{
	long long much;
	char z;
}a[500000];
long long n,ans=0,lon=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].much>>a[i].z;
	}
	int l=1,r=n;
	while(l<r){
		long long b=min(a[l].much,a[r].much);
		if(a[l].z!=a[r].z)ans+=b;
		a[l].much-=b;
		a[r].much-=b;
		if(a[l].much==0){
			l++;
		}
		if(a[r].much==0){
			r--;
		}
	}	
	cout<<ans<<endl;
	return 0;
}
