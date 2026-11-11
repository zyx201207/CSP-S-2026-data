#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int c;
	string m;
	string s={};
	for(int i;i>=0;i<n){
		cin>>c;
		cin>>m;
		for(int i;i>=0;i<c){
		s+=m; 
	    }	
	}
	
	cout<<s;
	return 0;
}

