#include<bits/stdc++.h>
using namespace std;
long long m;
long long a[50000005];

long long dg(long long s){
	if(s==1){
		return -a[1];
	}
	else {
		return a[s]+dg(s-1);
	}	
}
int main(){	
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);	
	long long n;
	long long ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;
	
	for(int i=2;i<=n;i++){
		if(dg(i)<=m){
			ans=i;
		}
		else{
			break ;
		}
	}
			cout<<ans;
	return 0;
}