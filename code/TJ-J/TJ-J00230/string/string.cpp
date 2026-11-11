#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a;
	string s,c; 
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long cnt=0;
	long long l=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[l-i-1]) cnt++;
	}
	cout<<cnt/2;
	return 0;
} 


























































