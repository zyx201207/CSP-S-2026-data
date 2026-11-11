#include<iostream>
using namespace std;
int m,n,a[100],b=0;
int main(){
freopen("crystal.in""n".stdin);
freopen("crystal.out""w".stdout);
cin>>m>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b=(a[i]++)/8;
		}
	
	cout<<b+2;
return 0;
}
