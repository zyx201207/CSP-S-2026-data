#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a,b,s=0,s1=0;
	char c[5],d[5];
	cin>>a;
	for(int i=1;i<=3;i++)
	{
		cin>>c[i];
	}
	cin>>b;
	for(int i=1;i<=3;i++)
	{
		cin>>d[i];
	}
	if(a==b)
	{
		cout<<"1";
	}
	else
		cout<<"0";
	if(c[1]==d[1]&&c[2]==d[2])
	{
		cout<<"1";
	}
	else
			cout<<"0";

	if(c[1]==d[1]&&c[2]==d[2])
	{
		if((c[3]=='A'||c[3]=='B'||c[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C'))
		{
				cout<<"1";
				s=1;
		}
		else
        {
            cout<<"0";
            s1=1;
        }

		if((c[3]=='D'||c[3]=='F')&&(d[3]=='D'||d[3]=='F'))
		{
			cout<<"1";
			s=1;
		}
		else if(s1!=1)
			cout<<"0";
	}
	else
        cout<<"0";
	if(s==1&&abs(c[3]-d[3])==1)
	cout<<"1";
	else
        cout<<"0";
	return 0;
}



