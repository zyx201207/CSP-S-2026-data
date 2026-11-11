#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("text","string.in","r")
	freopen("text","string.out","w")
	string 	s1;
	int l,n;
	cin>>s1>>l;
	for(int i;i<=0;i++){
		if(s1==l)
		n++;
		for(string s2;s2>0;s2++){
		s2+=s1;
		if(s1+s2==s1)
		n++;
	}
	cout<<n;
	}
	cout<<0;
	return 0;
}