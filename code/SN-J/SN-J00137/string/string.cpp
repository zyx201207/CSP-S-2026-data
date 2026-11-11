#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	string s="";
	for (long long i=0;i<n;i++){
		long long num;
		char b;
		cin>>num>>b;
		for (long long j=0;j<num;j++){
			s+=b;
		}
	}
	if (s.size()%2==0){
		long long x=s.size()/2;
		for (long long i=0;i<x;i++){
			if (s[i]!=s[s.size()-i-1]){
				sum++;
				s[s.size()-i-1]=s[i];
			}
		}
	}
	else{
		long long y=s.size()/2;
		for (long long i=0;i<y;i++){
			if (s[i]!=s[s.size()-i-1]){
				sum++;
				s[s.size()-i-1]=s[i];
			}
		}
	}
	cout<<sum;
	return 0;
}
