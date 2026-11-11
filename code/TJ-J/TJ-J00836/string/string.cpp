#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	long long num=s.length();
	long long l=0;
	long long r=num-1;
	long long ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
