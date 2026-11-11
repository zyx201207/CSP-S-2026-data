#include<bits/stdc++.h>
#define long long int
using namespace std;
int n,m,arr[500005],sum,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	if(x==1);
	cin>>arr[i];
}
		for(long long i=1,i<=n;i++;){
			if(((arr[2]-arr[1])+(arr[i]-arr[i-1]))*arr[i]/2<=m){
				sum=max(sum,i);
			}
			cout<<((arr[2]-arr[1])+(arr[i]-arr[i-1]))*arr[i]/2<<"\n";
	}
	cout<<sum;
	return 0;
}