#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt = 0,sum = 0;
	string x,y;
	cin>>n;
	for(int i = 0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		for(int i = 1;i<=a;i++){
			x+=b;
		}
	}for(int i = 0;i<n/2;i++){
		if(x[i] != x[i+n-1]){
			cnt++;
		}
	}
	/*string u;
	for(int i = x.size()-1;i>=0;i--){
		u += x[i];
	}
	for(int i = 0;i<x.size()/2;i++){
		if(x[i] != u[i]){
			cnt++;
		}
	}*/	
	cout<<cnt;	
	return 0;
}

