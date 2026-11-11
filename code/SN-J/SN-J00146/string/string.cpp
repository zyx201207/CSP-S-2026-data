#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	string s,m;
	long long n,p=0,sum=0;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++){
		long long b;
		string c;
		cin>>b>>c;
		for(int j=0;j<b;j++){
			s+=c;
			p++;
		}
	}
	for(int i=p-1;i>=0;i--){
		m+=s[i]; 
	}
	for(int i=0;i<p;i++){
		if(s[i]!=m[i]){
			sum++;
		}
	}
	cout<<sum/2;
	
	return 0;
}
