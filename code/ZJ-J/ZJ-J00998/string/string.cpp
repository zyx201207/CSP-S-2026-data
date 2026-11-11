#include<bits/stdc++.h>
using namespace std;
int n;
struct s
{
	long long num;
	string xxx;
};
s a[201000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s="";
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].xxx;
	}
	int i=1,j=n;
	long long head=a[i].num,tail=a[j].num;
	while(i<=j)
	{
		if(head==0)
		{
			head=a[i].num;
		}
		if(tail==0)
		{
			tail=a[j].num;
		}
		if(a[i].xxx!=a[j].xxx)
		{
			if(head>tail)
			{
				ans+=tail;
				head-=tail;
				tail=0;
				j--;
			}
			else if(head<tail)
			{
				ans+=head;
				tail-=head;
				head=0;
				i++;
			}
			else if(head==tail)
			{
				ans+=head;
				head=0;
				tail=0;
				i++;
				j--;
			}
		}
		else
		{
			if(head>tail)
			{
				head-=tail;
				tail=0;
				j--;
			}
			else if(head<tail)
			{
				tail-=head;
				head=0;
				i++;
			}
			else if(head==tail)
			{
				head=0;
				tail=0;
				i++;
				j--;
			}			
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
