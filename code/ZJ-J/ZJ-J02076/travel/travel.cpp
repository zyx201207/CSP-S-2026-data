#include<bits/stdc++.h>
using namespace std;
long long a,b;
string s1,s2;
bool fla=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"0000";
		fla=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&fla==0)
	{
		cout<<1;
	}
	else if(fla==0){
		cout<<"000";
		fla=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&fla==0&&!(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'))
	{
		cout<<1;
	}else if(fla==0){
		cout<<"00";
		fla=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&fla==0&&(s1[2]-s2[2]==-1||s1[2]-s2[2]==1)&&!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))
	{
		cout<<1;
	}else if(fla==0){
		cout<<"0";
		fla=1;
	}
	
	return 0;
}
