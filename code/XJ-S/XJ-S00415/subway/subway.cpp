#include <iostream> 
#include <algorithm> 
#include <bits\stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
struct station
{
	int id;
	int en2ga;
};
struct line
{
	int n1;
	int n2;
	int time;
};
bool tu(line a,line b)
{
	return a.n1<b.n1;
	return a.n2<b.n2;
	return a.time<b.time;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,t1,t2[n*d],com;
	cin>>c>>n>>m>>d>>q;
	station B[m+2];line L[((n*(n+1))/2)+2];
	for(int i=1;i<=m;i++)
	{
		cin>>B[i].en2ga;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t1;
		for(int j=1;j<=2*t1;j++)
		{
			cin>>t2[j];	
		}
		for(int j=1;j<=t1-1;j++)
		{
			for(int k=1;k<=t1-1;k++)
			{
				L[(t1-1)*j+k].n1=t2[2*j-1];
				L[(t1-1)*j+k].n2=t2[2*k+1];
				L[(t1-1)*j+k].time=t2[2*k]+t2[2*k+2];
			}
		}
	}
	sort(L+1,L+1+((n*(n+1))/2),tu);
	int st,ed,ti=0;
	for(int i=0;i<q;i++)
	{
		com=0;
		cin>>st>>ed;ti=B[st].en2ga+B[ed].en2ga;
		for(int j=1;j<=((n*(n+1))/2);j++)
		{
			if((L[j].n1==st&&L[j].n2==ed)||(L[j].n2==st&&L[j].n1==ed)) 
			{
				ti+=L[j].time;
				cout<<ti;com=1;
			}
		}
		if(com!=1)
		{
			for(int j=1;j<=((n*(n+1))/2);j++)
			{
				if(j==st)
				{
					j+=1;
				}
				for(int k=1;k<=((n*(n+1))/2);k++)
				{
					if(L[k].n1==st&&L[k].n2==j||(L[k].n2==st&&L[k].n1==j)) 
					{
						ti+=L[k].time;
						st=j;k=((n*(n+1))/2)+2;
						if(j==ed)
						{
							cout<<ti;j=((n*(n+1))/2)+2;
						}
					}
				}
			}
		}
		//too winded
	}
	cout<<"";
	return 0;
}
   

