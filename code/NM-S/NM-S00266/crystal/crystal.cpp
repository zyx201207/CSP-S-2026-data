#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum=0,mx=-1,sl=0;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=0;i--){
		for(int j=0;j<n-i-1;j++){
			sum+=a[i]-a[j];
			
		}
		if(sum%m==0&&sum>mx){
			mx=sum;
			cout<<i-2<<" ";
		}
	}
	return 0;
}
