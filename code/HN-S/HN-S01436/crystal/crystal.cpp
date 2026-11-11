#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	long long n,m,a[50005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	int maxx=0,minn=99999999999999;
	for(int i=1;i<=n;i++){
		if(a[i]<minn){
			minn=a[i];
		}
		if(minn+m>=a[i]){
			maxx=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==maxx){
			sum++;
		}
		for(int j=1;j<=m;j++){
			if(a[i]+j==maxx){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
