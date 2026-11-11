#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=1;i<=a;i++){
			s=s+c;
		}
	}
	for(long long i=s.size()-1;i>=0;i--){
		s1=s1+s[i];
	}
	long long sum=0;
	for(long long i=0;i<s.size();i++){
		if(s1[i]!=s[i]){
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
}
