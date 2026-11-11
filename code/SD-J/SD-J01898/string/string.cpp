#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,A[200000]; 
struct node{
	long long a,num;
	char c;
}str[500000];
vector<node> v1,v2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long q,w=0,e,r=0,i,j,x,y;
	char c;
	node nnn;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str[i].a>>str[i].c;
		str[i].num=str[i].a+str[i-1].num;
	}
	q=str[n].num;
	int q1=q/2;
	for(i=1;i<=n;i++)
	{
		w=str[i].num;
		if(w>=q1)
		{
			e=i+1;
			if(w==q1)
			{
				v1.push_back(str[i]);
				break;
			}
			else
			{
				nnn.a=q1-str[i-1].num;
				nnn.c=str[i].c;
				nnn.num=q1;
				v1.push_back(nnn);
				nnn.a=str[i].num-q1;
				nnn.num=str[i].num;
				r=1;
			}
			break;
		}
		v1.push_back(str[i]);
	}
	for(i=n;i>=e;i--)
	{
		v2.push_back(str[i]);		
	}
	if(r==1) v2.push_back(nnn);
	if(q%2==1)
	{
		v2[v2.size()-1].a--;
	}
	
	x=0;y=0;
	long long xx=0,yy=0;
	char c1,c2;
	while(x<v1.size() || y<v2.size())
	{
		if(xx<=yy)
		{
			xx=v1[x].num;
			c1=v1[x].c;
			if(xx<=yy)
			{
				if(c1!=c2&&y!=0)
				{
					ans+=v1[x].a;
				}
			}
			else
			{
				if(c1!=c2&&y!=0)
				{
					ans+=yy-v1[x-1].num;
				}
			}
			x++;
		}
		else
		{
			yy+=v2[y].a;
			c2=v2[y].c;
			if(yy<=xx)
			{
				if(c1!=c2)
				{
					ans+=v2[y].a;
				}
			}
			else
			{
				if(c1!=c2)
				{
					ans+=xx-(yy-v2[y].a);
				}
			}
			y++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 //<<fixed<<setprecision(2);
 
