#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int a;
	char c;
}z[N];
int main(){
	freopen("string.in","r",stdin);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i].a>>z[i].c;
	}
	string s,s2;
	s2+' ';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=z[i].a;j++) s+=z[i].c;
	}
	int len=s.size()-1;
	for(int i=len/2;i>=0;i--){
		s2+=s[i];
	}
	for(int i=len/2;i<=len;i++){
		if(s[i]!=s2[i-len/2]) cnt++;
	}
	cout<<cnt;
	freopen("string.out","w",stdout);
	return 0;
}
