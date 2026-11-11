#include<bits/stdc++.h>
using namespace std;
long long ok1=1,ok2=1,ok3=0,ok4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(size_t i=0;i<c1.size();i++)
	{
		if(c1[i]!=c2[i]) ok1=0;
	}
	if(ok1==0)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	string s11=s1.substr(0,2);
	char s12=s1[2];
	string s21=s2.substr(0,2);
	char s22=s2[2];
	for(size_t i=0;i<s11.size();i++)
	{
		if(s11[i]!=s21[i]) ok2=0;
	}
	if(ok2==0)
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if((s12-'A'<=2)&&(s22-'A'<=2)) ok3=1;
	else if((s12-'A'>2)&&(s22-'A'>2)) ok3=1;
	else ok3=0;
	if(ok3==0)
	{
		cout<<"1100"<<endl;
		return 0;
	}
	if((s12=='A'&&s22=='B')||(s12=='B'&&s22=='A')) ok4=1;
	else if((s12=='B'&&s22=='C')||(s12=='C'&&s22=='B')) ok4=1;
	else if((s12=='D'&&s22=='F')||(s12=='F'&&s22=='D')) ok4=1;
	else ok4=0;
	cout<<ok1<<ok2<<ok3<<ok4<<endl;
	return 0;
}
