#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long>a(n);
	vector<char>b(n);
	string s,s_;
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i];
	}
	
	long long ij=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<a[i]; j++){
			s[ij]=b[i];
			ij++;
		}
	}
	ij=0;
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<a[i]; j++){
			s_[ij]=b[i];
			ij++;
		}
	}
	for(int i=0; i<ij; i++){
		if(s[i]!=s_[i]){
			cnt++;
		}        
		 	
	}
	 
	cout<<cnt/2;
	return 0;
}