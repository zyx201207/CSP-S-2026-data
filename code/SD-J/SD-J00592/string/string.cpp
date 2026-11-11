#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n],anum,num=0,e=0;
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		anum+=a[i];
	}char s[anum];
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[num]=c[i];
			num++;
		}
	}
	if(anum%2==1){
		anum--;
		e++;
	}
	int ybda=anum*0.5,o=0;
	char ls[ybda],rs[ybda];
	for(int i=0;i<ybda;i++){
		ls[o]=s[i];
		o++;
	}o=0;
	for(int i=0;i<ybda;i++){
		rs[o]=s[i+e+ybda];
		o++;
	}o=0;
	for(int i=0;i<ybda;i++){
		if(ls[i]!=rs[i]){
			o++;
		}
	}
	cout<<o;
	return 0;
}
