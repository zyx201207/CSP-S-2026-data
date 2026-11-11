#include<bits/stdc++.h>
using namespace std;
string p1,p2;
long long w1,w2,a[5]={0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>w1>>p1>>w2>>p2;
	if(w1!=w2) a[0]=0;
	else
	{
		a[0]=1;
		if(p1[0]==p2[0]&&p1[1]==p2[1]) a[1]=1;
		{
			if((p1[2]=='A'||p1[2]=='B'||p1[2]=='C')&&(p2[2]=='A'||p2[2]=='B'||p2[2]=='C')||(p1[2]=='D'||p1[2]=='F')&&(p2[2]=='D'||p2[2]=='F')) a[2]=1;
			{
				if(p1[2]=='C'&&p2[2]=='D'||p2[2]=='C'&&p1[2]=='D') a[3]=0;
				else if(((p2[2]-'A')-(p1[2]-'A')==1||(p1[2]-'A')-(p2[2]-'A')==1)||(p1[2]=='D'&&p2[2]=='F')||(p2[2]=='D'&&p1[2]=='F')) a[3]=1;
			}
    	}
	}
	for(int i=0;i<=3;i++) cout<<a[i];
	return 0;
}