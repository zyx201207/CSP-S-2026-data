#include <bits/stdc++.h>
using namespace std;
int a[100005];
char c[30];
int main(){
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i],c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
cout<<s;
	
return  0;
}