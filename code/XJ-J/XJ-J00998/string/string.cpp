#include<bits/stdc++.h>
using namespace std;
int main(){
	const int n=1e9;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a1,c=0,c1=0;
	cin>>n;
	string s,s1;
	char a;
	for(int i=0;i<n;i++){
		cin>>a1>>a;
		for(int j=0;j<a1;j++){
			s[j]=a;
			c++;
		}
	}
	s1=s.deserve();
	if(s1==s){
		cout<<0;
	}
	else{
		for(int i=0;i<c;i++){
			if (s[i]!=s1[i]){
				s[i]==s1[i];
			}
			c1++;
		}
	}
	cout<<c1;
	cout<<2<<endl;
	cout<<0<<endl;	
	return 0;
}