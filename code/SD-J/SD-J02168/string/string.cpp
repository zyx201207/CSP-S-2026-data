#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200000];
	char b[200000];
	string c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			c+=b[i];
		}
	}	
	for(int i=0;i<(c.size()/2);i++){
		if(c[i]!=c[c.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
