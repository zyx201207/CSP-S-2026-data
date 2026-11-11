#include<bits/stdc++.h>
using namespace std;
string s="";
long long num=0,cnt,n;
char m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt>>m;
		for(long long j=1;j<=cnt;j++){
			s+=m;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) num++;
	}
	cout<<num;
	return 0;


} 
