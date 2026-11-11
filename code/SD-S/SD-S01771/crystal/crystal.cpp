#include <bits/stdc++.h>
using namespace std;
int a[100000];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=a[2]-a[1];
	int zy=m;
	for(int i=0;i<n-1;++i){
		zy=zy-i*s;
		if(zy==0){
			cout<<i+1;
			return 0;
		}
		if(zy<0){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
