#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c_1,c_2,s_1,s_2;
	char s1,s2;
	cin>>c_1;
	s1=getchar();
	s1=getchar();s_1=10*(s1-'0');
	s1=getchar();s_1+=(s1-'0');
	s1=getchar();
	cin>>c_2;
	s2=getchar();
	s2=getchar();s_2=10*(s2-'0');
	s2=getchar();s_2+=(s2-'0');
	s2=getchar();
	if(c_1==c_2) cout<<1;
	else{cout<<"0000";return 0;}
	if(s_1==s_2) cout<<1;
	else{cout<<"000";return 0;}
	if((s1>='A'&&s1<='C'&&s2>='A'&&s2<='C')||(s1>='D'&&s1<='F'&&s2>='D'&&s2<='F')) cout<<1;
	else{cout<<"00";return 0;}
	if(s1>s2) swap(s1,s2);
	if(s1!='C'&&s2==s1+1) cout<<1;
	else cout<<0;
	return 0;
}

