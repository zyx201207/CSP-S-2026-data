#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector <char>x;
	vector <char>y;
	vector <char>b;
	string z;
	int n,sum=0;
	char a[10005];
	cin>>n;
	for (int i=0;i<n*2;i++){
		cin>>a[i];
	}
	for (int i=0;i<n*2;i=i+2){
			x.push_back(a[i]);	
	}
	for (int i=1;i<n*2;i=i+2){
			y.push_back(a[i]);	
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<x[i]-48;j++){
				b.push_back(y[i]);
				sum++;
		}
	}
	int bj=0,sz=0;
	for (int i=0;i<sum/2;i++){
		for (int j=sum-1;j>sum/2;j--){
			if (b[i]!=b[j]){
				bj=1;
				sz++;
			}
		}
	}
	if (bj==1){
		cout<<sz/2;
	}
	else{
		cout<<0;
	}
    return 0;	
}
