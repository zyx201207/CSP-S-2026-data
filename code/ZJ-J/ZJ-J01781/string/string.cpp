#include<bits/stdc++.h>
using namespace std;
int n,x,sum;
char ch;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>ch;
		for(int i=1;i<=x;i++){
			s+=ch;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			sum++;
		}
	}
	cout<<sum;
}