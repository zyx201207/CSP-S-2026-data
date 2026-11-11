#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
long long n;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long left=0;
	long long right=s.size()-1;
	while(left<=right){
		if(s[left]!=s[right])ans++;
		left++;
		right--;
	}
	cout<<ans;
	return 0;
}