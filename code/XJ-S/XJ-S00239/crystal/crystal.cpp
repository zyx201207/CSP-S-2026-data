#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,p;
	long long int a[250000+5];
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	p=a[2]-a[1];
	for(long long i=1;i<=n;i++){
		sum+=(p*i);
		if(sum>m){
			cout << i-1;
			return 0;
		}
	}
	return 0;
} 
