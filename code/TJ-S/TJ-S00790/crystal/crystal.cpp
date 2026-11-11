#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n); 
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(num>=m){
				break;
			}
			while(a[i]==a[i-1] || num>=m){
				a[i]++;
				num++;
			}
		}
	}
	int num1=0;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
		if(a[i]==a[i+1]){
			num1++;
		}
	}
	cout<<num1;
	return 0;
}
