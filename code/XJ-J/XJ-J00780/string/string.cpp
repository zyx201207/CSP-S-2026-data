#include<bits/stdc++.h>
using namespace std;
int cnt;
long long int n,a;
string s,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	int x=s.size();
	if(x%2==0){
		for(int i=0;i<=x/2;i++){
			if(s[i]!=s[x-i]) cnt++;
		}
	}
	else{
		for(int i=0;i<x/2;i++){
			if(s[i]!=s[x-i-1]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}