#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	long long a[2005];
	string b[55];
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
	}
	
	vector<string> s;
	for(int i=0;i<n;++i){
		while(a[i]>0){
			s.push_back(b[i]);
			a[i]--;
		}
	}//Ω‚—π 
	
	vector<string> ss;
	for(int i=s.size();i>0;--i){
		ss.push_back(s[i]);
	}
	
	long long sum=0;
	for(int i=0;i<s.size();++i){
		if(s[i]!=ss[i]) sum++;
	}
	cout<<sum;
	return 0;
} 
