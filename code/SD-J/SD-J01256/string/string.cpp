#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0;
	long long d=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		s+=b[i];
		d+=a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i-1]){
			c++;
		}
	}
	if(c==0){
		cout<<0;
	}
	else{
		cout<<d/2;
	}
	return 0;
} 

