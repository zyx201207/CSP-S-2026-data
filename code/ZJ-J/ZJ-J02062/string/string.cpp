#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int a[n],z=0;
	string b;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b;
		for(int j=0;j<a[i];j++){
			s[z]=b[i];
			z++;
		}
	}
	
	
	
	return 0;
}