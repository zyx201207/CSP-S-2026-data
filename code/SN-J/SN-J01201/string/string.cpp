#include<iostream>
using namespace std;
long long n,a[200010],js,ls;
char c[900000000];
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		for(int k=1;k<=a[i];k++,ls++){
			c[ls]=b;
		}
	}
	for(int i=0,j=ls-1;i<j;i++,j--){
		if(c[i]!=c[j])js++;
	}
	cout<<js;
	return 0;
}
