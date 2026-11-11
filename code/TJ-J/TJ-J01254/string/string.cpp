#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string l;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			l.push_back(y);
		}
	}
	long long sum=0;
	for(long long i=l.size()/2-1;i>=0;i--){
		if(l[i]!=l[l.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
