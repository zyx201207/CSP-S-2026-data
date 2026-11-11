#include<bits/stdc++.h>
using namespace std;
long long mj(int c[],long long n){
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(c[i]==c[j]) ans++;
		}
	}
	return ans;
}
int a[1000000],b[1000000],c[1000000];
int main( ){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			
		}
	}*/
	if(m%2==0) cout<<m/2;
	else cout<<m/2+1;
	return 0;
	}
