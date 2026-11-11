#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,c=0;
	cin>>n;
	string s1="",s2="";
	while(n--){
		long long int a;
		cin>>a;
		c+=a;
		string s_;
		cin>>s_;
		for(int i=0;i<a;i++){
			s1=s1+s_;
		}
	}
	for(int i=c-1;i>=0;i--){
		s2=s2+s1[i];
	}
	long long c2=0;
	for(int i=0;i<c;i++){
		if(s1[i]!=s2[i]){
			c2++;
		}
	}
	cout<<c2/2;
	return 0;
}

