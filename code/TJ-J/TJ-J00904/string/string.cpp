#include<bits/stdc++.h>
using namespace std;
int n,s;
char ch; 
string s1,s2;
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		cin>>ch;
		for(int i=0;i<s;i++){
			s1+=ch;
		}
	}
	int f=s1.size();
	for(int i=f;i>0;i++){
		s2+=s1[i];
	}
	if(s1==s2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
} 
