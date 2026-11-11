#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	int n;
	int x;
	string y;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=0;j<x;j++){
			a+=y;
		}
	}
	for(int i=0;i<a.size();i++){
		if(a[i]!=a[a.size()+1-i]&&a.size()+1-i<a.size()){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


