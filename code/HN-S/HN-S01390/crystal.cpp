#include<bits/stdc++.h>
using namespace std;
long long n,m,kk,zz;
long long a[1000005];
bool ygcxy(int x,int y){
	return x>y;
}
int main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int g=0;
	if(n%2==0){
		g=n/2;
	}else{
		g=n/2+1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[g]){
			zz++;
		}
	}
	for(int i=g-1;i>0;i--){
		if(a[i]<=m){
			m=m-(a[g]-a[i]);
			kk++;
		}else{
			break;
		}
	}
	cout<<kk+zz;
	return 0;
}
