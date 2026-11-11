#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,x,sum=0;
	char c;
	char l[100000];
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x>>c;
		for(long long j=0;j<x;j++){
			l[sum]=c;
			sum++;
		}
	}
	long long final=0;
	for(long long i=0;i<sum/2;i++){
		if(l[i]!=l[sum-i-1]){
			final++;
		}
	}
	cout<<final;
	return 0;
}
