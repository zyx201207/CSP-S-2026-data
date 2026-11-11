#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,cmp;
	long long a[100001];
	char b[100001];
	string c;
	
	
	cin>>s;
	int count=0;
	for(int i=1;i<=s;i++){
		cin>>a[i];
		cin>>b[i];
		for(int j=1;j<=a[i];j++){
			count++;
			c[count]=b[i];
			
		}
	}

	
	int sum=0;
	for(int i=1;i<=count/2;i++){
		if(c[i]!=c[count]){
			sum++;
		}
	}
	cout<<sum;
}
