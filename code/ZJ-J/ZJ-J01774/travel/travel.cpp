#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) a[1]=1;
	else{
		cout<<"0000";
		return 0;
	}
	string ch="";
	string ch1="";
	for(int i=0;i<2;i++) ch=ch+s2[i],ch1=ch1+s4[i];
	if(ch==ch1){
		a[2]=1;
		if(s2[2]-'A'+1<=3&&s4[2]-'A'+1<=3||s2[2]-'A'+1>3&&s4[2]-'A'+1>3){
			a[3]=1;
			int x=s2[2]-'A'+1;
			int y=s4[2]-'A'+1;
			if(abs(x-y)==1) a[4]=1;
		}
	}
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
}