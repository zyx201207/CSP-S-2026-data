#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	char b[n];
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	int sum=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
