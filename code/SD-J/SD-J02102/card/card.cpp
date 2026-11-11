#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],sta[N],la=1,
b[N],ans[N],nowans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>1;i--)
	{
		sta[la++]=a[i];
		nowans[a[i]]++;
		if(b[a[i]] && la-1)
		{
			la--;
			while(sta[la-1]!=a[i])
			la--,nowans[sta[la]]=0,b[sta[la]]=0;
			nowans[a[i]]=1;
		}
		b[a[i]]=1;
		cout<<la<<"->";
		for(int j=1;j<la;j++)
		cout<<sta[j]<<' ';
		cout<<"        ";
		for(int j=1;j<=m;j++)
		cout<<nowans[j]<<' ';
		cout<<endl;
		for(int j=1;j<=m;j++)
		ans[j]+=nowans[j];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*

10 3
3 1 2 1 3 2 3 1 2 1
*/
/*

4 3
1 2 1 3
*/

