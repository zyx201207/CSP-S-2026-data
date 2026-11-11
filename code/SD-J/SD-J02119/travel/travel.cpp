#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n,m,f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)	cout<<1;
	else{
		f=0;
		cout<<0;	
	}
	for(int i=0;i<s1.size()-1;i++){
		int pos=10;
		n+=(s1[i]-'0')*pow(pos,i);
	}
	for(int i=0;i<s2.size()-1;i++){
		int pos=10;
		m+=(s2[i]-'0')*pow(pos,i);
	}
	if(n==m&&f==1)	cout<<1;
	else{
		f=0;
		cout<<0;
	}
	if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'&&f==1){
		cout<<1;
	}else if(s2[2]=='C'||s2[2]=='B'||s2[2]=='A'&&s1[2]!='F'&&s1[2]!='D'&&f==1){
		cout<<1;
	}else {
		f=0;
		cout<<0;
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2])	cout<<1;
	else cout<<0;
	return 0;
}
