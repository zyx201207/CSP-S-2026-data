//姓名：高梓宸    学校：西安辅轮中学    SN-J00795
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int st[5]={},top=0;
	int flag=0;
	
	
	if(a==c)
	{
		st[top++]=1;
		flag=1;
	}
	else
	{
		st[top++]=0;
		flag=0;
	}

	
	if(b[0]==d[0]&&b[1]==d[1]&&flag==1)
	{
		st[top++]=1;
		flag=1;
	}
	else
	{
		st[top++]=0;
		flag=0;
	}
	
	
	if(flag==1&&(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'))
	{
		st[top++]=1;
		flag=1;
	}
	else
	{
		st[top++]=0;
		flag=0;
	}
	
	
	char x=b[2]-d[2];
	if((x==1||x==-1)&&flag==1)
	{
		st[top++]=1;
		if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C'))
		{
			st[top-1]=0;
		}
	}
	else
	{
		st[top++]=0;
	}
	
	
	for(int i=0;i<top;i++)
	{
		cout<<st[i];
	}
	return 0;
}
