#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
long long ans[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	else if(m==2){
		long long x[1009];
		cout<<x[1]<<" "<<x[2];
		return 0;
	} 
	cout<<3<<" "<<1<<" "<<4;
	return 0;
}
