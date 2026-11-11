#include <bits/stdc++.h>
using namespace std; 
string s;
string k;
int max0=100000000;
int dfs(string a,int q){
	bool f=1;
	for(int i=0;i<a.size();i++){
		if(a[i]!=a[a.size()-1-i]){
			f=0;
		}
	}
	if(f==1&&max0>q){
		max0=q;
	}
	for(int i=0;i<a.size();i++){
		k=a;
		if(a[i]!=a[a.size()-1-i]){
			a[i]=a[a.size()-1-i];
			q++;
			dfs(a,q);
			a[i]=k[i];
		}
	}
	return max0;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	string b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s=s+b;
		}
	}
	cout<<dfs(s,0);
	return 0; 
} 
