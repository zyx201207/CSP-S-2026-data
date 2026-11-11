#include<bits/stdc++.h>
using namespace std;
long long int n,a,m=0,q=0;
string b,c;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b[i];
		m+=a;
		for(int j=0;j<a;j++){
		    c+=b[i];
		}
	}
	for(long long int i=0;i<m/2;i++){
		if(c[i]!=c[m-i-1]){
			q+=1;
		}
	}
	cout<<q;
}