#include<bits/stdc++.h>
using namespace std;
int x,y,b[105];
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	if(x==y)b[1]=1;//条件1 
	if(b[1]==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b[2]=1;
		}
	}//条件2 
	if(b[2]==1){
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
		{
			b[3]=1;
		}
	}//条件3 
	if(b[3]==1){
		if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))b[4]=1;
		//else if(((s1[2]=='A'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B'))||((s1[2]=='C'||s1[2]=='B')&&(s2[2]=='C'||s2[2]=='B')))b[4]=1;
		else if(s1[2]+1==s2[2]||s1[2]-1==s2[2])b[4]=1;
	}
	for(int i=1;i<=4;i++){
		cout<<b[i];
	}
	return 0;
 } 
