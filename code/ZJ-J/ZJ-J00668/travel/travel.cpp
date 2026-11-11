#include<bits/stdc++.h>
using namespace std;
string s,st,ss,stt;
bool p,pt,pth,pf;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>st>>ss>>stt;
	if(s[0]==ss[0]&&s[1]==ss[1])
	{
		cout<<1;
		if(st[0]==stt[0]&&st[1]==stt[1])
		{
			cout<<1;
			char s_=st[2],ss_=stt[2];
			if(s_>ss_)
			{
				swap(s_,ss_);
			}
			if(s_=='A'&&(ss_=='B'||ss_=='C')||s_=='D'&&ss_=='F')
			{
				cout<<1;
				if((s_=='A'&&ss_=='B')||(s_=='B'&&ss_=='C')|(s_=='D'&&ss_=='F'))
				{
					cout<<1;
				}
				else
				{
//					cout<<04;
					pf=1;
				}
			}
			else
			{
//				cout<<03;
				pth=1;
			}
		}
		else
		{
//			cout<<02;
			pt=1;
		}
	}
	else
	{
//		cout<<01;
		p=1;
	}
	if(p==1)
	{
		cout<<"0000";
	}
	if(pt==1)
	{
		cout<<"000";
	}
	if(pth==1)
	{
		cout<<"00";
	}
	if(pf==1)
	{
		
		cout<<"0";
	}
	return 0;
}