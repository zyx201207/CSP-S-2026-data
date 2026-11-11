#include<bits/stdc++.h>
using namespace std;
long long n,a,s=0;
char c;
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			x.push_back(c);
		}
	} 
	if(x.size()%2==1){
		for(int i=0;i<(x.size()-1)/2;i++){
			if(x[i]!=x[x.size()-1-i])
			    s++; 
		}
	}
	else{
		for(int i=0;i<x.size()/2;i++){
			if(x[i]!=x[x.size()-1-i])
			   s++; 
		}
	}
	cout<<s;
	return 0;
} 
