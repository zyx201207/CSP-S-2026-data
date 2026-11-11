#include<bits/stdc++.h>
using namespace std;
int a[10005];
char c[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		if(c[i]==c[i+1]) cout<<"0";
	}
	
	return 0;
} 
