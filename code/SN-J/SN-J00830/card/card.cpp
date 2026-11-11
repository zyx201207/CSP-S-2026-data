//李铭宸 西安交通大学附属中学 SN-J00830
#include <bits/stdc++.h>
using namespace std;
int a[100005],ans[100005];
int qj[100005];
int s;	
int top=0;
void sdl()
{
	int cnt=0;
	for(int i=top;i>=1;i--)
	{
		a[qj[i]]--;
		if(qj[i]==top) cnt++;
		if(cnt==2) top=i-1;
	}
}
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>qj[++top];
		a[qj[top]]++;
		if(a[qj[top]]==2)
		{
			sdl();
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=a[j];;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
