#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	string s2;
	s2=s;
	reverse(s2.begin(),s2.end());
	if(s==s2){
		cout<<0;
		return 0;
	}
	long long sum=0;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s2[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
