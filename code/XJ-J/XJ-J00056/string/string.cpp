#include<bits/stdc++.h>

using namespace std;
int x;
char s;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	string c="";
	for(int i=0;i<n;i++){
		cin>>x>>s;
		for(int j=0;j<x;j++)
			c+=s;
	}
	int mid=(c.size())/2;
	for(int i=0;i<=mid;i++){
		if(c[i+mid]!=c[mid-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
