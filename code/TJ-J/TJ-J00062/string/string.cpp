#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	string s1;
	for(int i=1;i<=n;i++){
		long long a=s1.size();
		cin>>a;
		cin>>s1[0];
		for(int i=0;i<a;i++){
			s1[i]=s[0];
			s+=s1[1];
		}
	}
	long long cnt=0;
	long long x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]!=s[x-1-i]){
			cnt++;
		}
	}
	int ans=cnt/2;
	cout<<ans;
	return 0;
}
