#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1=="1"||c1=="16"||c2=="1"||c2=="16")return 0;
	if(c1==c2)cout << "1";
	else 
	{
		cout << "0000";
		return 0;
	}
	bool flag=1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])flag=0;
	}
	if(flag==1)cout << "1";
	else
	{
		cout << "000";
		return 0;
		
	} 
	char a1,a2;
	for(int i=0;i<3;i++)
	{
		if(s1[2]=='F')s1[2]='E';
		if(s2[2]=='F')s2[2]='E';
		a1=char(s1[2]);
		a2=char(s2[2]);
	}
	if(max(a1,a2)-min(a1,a2)>=3||(max(a1,a2)=='D'&&min(a1,a2)=='C'))cout << "0";
	else cout << "1";
	if(max(a1,a2)-min(a1,a2)==1&&max(a1,a2)!='D'&&min(a1,a2)!='C')cout << "1";
	else cout << "0";
	return 0;
}

