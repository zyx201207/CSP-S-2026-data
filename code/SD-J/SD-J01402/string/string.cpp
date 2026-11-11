#include<bits/stdc++.h>
using namespace std;
long long a;
int n,sum;
string c[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int b[n+1];
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i];
			sum+=b[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]==c[i+1]){
			a++;
		}
	}
	if(a==n-1){
		cout<<0;
	}
	a=0;
	string d[sum+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i];j++){
			d[j]=c[i];
		}
			}
	if(sum%2==0){
		for(int i=0;i<sum/2;i++){
			if(d[i]!=d[sum-1-i]){
				a++;
			}
		}
		cout<<a;
	}
	else{
		for(int i=0;i<sum/2;i++){
			if(d[i]!=d[sum-i-1]){
				a++;
				cout<<d[i]<<d[sum-i-1];
			}
		}
		cout<<a;
	}
	return 0;
} 
