#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[101],b[101],c[101],d[101];
	scanf("%s%s%s%s",a,b,c,d);
	if(a[0]!=c[0]||a[1]!=c[1]){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
		if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
		{
			cout<<"1";
		}
		else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
		{
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
		{
			if(abs((b[2]-'0')-(d[2]-'0'))==1)
			{
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
		{
			if(abs((b[2]-'0')-(d[2]-'0'))==1)
			{
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
} 
