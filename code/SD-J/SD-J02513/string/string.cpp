#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ji1=0,ji2=0;
	cin>>n;
	if(n<=1){
		cout<<0;
		return 0;
	}
	int a;
	string b,d;
	char c;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			b=b+c;
		}
	}
	for(int i=b.size()-1;i>=0;i--){
		d=d+b[i];
	}
	for(int i=0;i<b.size()/2;i++){
		if(d[i]!=b[i]){
			ji1++;
		}
	}
	for(int i=(b.size()+1)/2;i<b.size();i++){
		if(d[i]!=b[i]){
			ji2++;
		}
	}
	cout<<min(ji1,ji2);
	return 0;
} 
