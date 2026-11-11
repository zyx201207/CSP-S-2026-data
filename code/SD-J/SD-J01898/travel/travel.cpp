#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,A[200000]; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long q,w,e,r,i,j,x,y;
	string s1,c1,s2,c2,ss1,ss2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		ss1=s1[0]+s1[1];
		ss2=s2[0]+s2[1];
		if(ss1!=ss2)
		{
			cout<<"000";
		}
		else
		{
			cout<<1;
			q=s1[2]-'A'+1;
			w=s2[2]-'A'+1;
			if((q<=3&&w<=3)||(q>=4&&w>=4))
			{
				cout<<1;
				if(abs(q-w)==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 //<<fixed<<setprecision(2);
 
