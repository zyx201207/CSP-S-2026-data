#include<bits/stdc++.h>
using namespace std;
int n,a;
char ch;
string s;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//Trick||Treat!
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		for(int j=1;j<=a;j++){
			s+=ch;
		}
	}
	int x=s.size();
	for(int i=0;i<x/2;i++){
		if(s[i]!=s[x-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
}
