#include<bits/stdc++.h>
using namespace std;
char a[200000005]={};
int main(){
	int n,m;
	long long sum=0;
	char s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>s;
		for(int j=0;j<m;j++){
			a[i+j]=s;
		}
	}
	for(int i=0;i<n;i++){
		if(!(a[i]==a[n-i-1])){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
