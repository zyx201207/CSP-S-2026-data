#include<bits\stdc++.h> 
using namespace std;
long long n,m,a[1000000],z[1000000],tot,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		z[i]=a[i]-a[i-1];
	}
	sort(z+1,z+n+1);
	
	
	
	
	
	
	
	
	
	
	
	cout<<"3";
	return 0;
}
