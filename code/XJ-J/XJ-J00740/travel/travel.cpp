#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c1,c2,a=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
		
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<0;
			break;
		}
		if(i==1)
			cout<<1;
	}
	
	if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))
		a+=1;
	else
		a+=0;
	if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
		a+=1;
	else
		a+=0;
	if(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))
		a+=1;
	else
		a+=0;
	if(s1[2]=='D'&&s2[2]=='F')
		a+=1;
	else
		a+=0;
	if(s1[2]=='F'&&s2[2]=='D')
		a+=1;
	else
		a+=0;
	cout<<a;
	
	if((s1[2]=='A'||s1[2]=='C')&&s2[2]=='B')
		cout<<1;
	else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
		cout<<1;
	else if(s1[2]=='D'&&s2[2]=='F')
		cout<<1;
	else if(s1[2]=='F'&&s2[2]=='D')
		cout<<1;
	else
		cout<<0;
	return 0;
}