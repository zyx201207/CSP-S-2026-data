#include<bits/stdc++.h>
using namespace std;
int a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,c1,s,s1;
	cin>>c>>s>>c1>>s1;
	for(int i=0;i<4;i++){
		a[i]=0;
	}
	if(c!=c1) a[0]=0;
	else{
		a[0]=1;
		if((s[0]!=s1[0])||(s[1]!=s1[1])) a[1]=0;
		else{
			a[1]=1;
			if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(s1[2]=='D'||s1[2]=='F'))||((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s[2]=='D'||s[2]=='F')))
				a[2]=0;
			else{
				a[2]=1;
				if((s[2]=='C')&&(s1[2]=='D'))
					a[3]=0;
				else if((s[2]+1!=s1[2])&&(s[2]-1!=s1[2])) s[3]=0;
				else a[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
} 
