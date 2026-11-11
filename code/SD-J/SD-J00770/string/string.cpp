#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	int i,j;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int nu;
	char ch;
	for(i=1;i<=n;i++){
		cin>>nu>>ch;
		for(j=1;j<=nu;j++){
			s+=ch;
		}
	}
	unsigned long long su=0;
	i=s.size()/2;
	for(j=i;j>=0;j--){
		if(s[2*i-j]!=s[j]){
			su++;
		}
	}
	cout<<su<<'\n';
	return 0;
}
