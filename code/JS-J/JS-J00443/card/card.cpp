/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n,0),ans(m,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	for(int i=0;i<n;i++)
	{
		vector<int> last(m+10,-1),now(n+10,0);
		int len=i;
		for(int j=i;j<n;j++)
		{
			if(last[a[j]]!=-1)
			{
				if(len<last[a[j]])
				{
					last[a[j]]=len;
				}
				len=last[a[j]];
			}
			now[len]=a[j];
			last[a[j]]=len;
			len++;
//			cout<<"+++\n"<<len<<"\n\n";
		}
		for(int ss=i;ss<len;ss++) ans[now[ss]]++;
//		for(int ss=i;ss<len;ss++) cout<<now[ss]<<" ";
//		cout<<"\n\n---------"<<len<<"--------\n";
	}
	for(auto it:ans) cout<<it<<" ";
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	bool f=1;
	cin>>n>>m;
	vector<int> a(n+2,0),ans(m,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]--;
		if(f&&(a[i]>=a[i-1])) f=1;
		else f=0;
	}
	if(f)
	{
		for(int i=1;i<=n;i++) ans[a[i]]=i;
		for(auto it:ans) cout<<it<<" ";
		return 0;
	}
	if(n>32000)
	{
		for(int i=1;i<=n;i++)
		{
			vector<int> last(m+10,-1),now(n+10,0);
			int len=i;
			for(int j=i;j<n;j++)
			{
				if(last[a[j]]!=-1)
				{
					if(len<last[a[j]])
					{
						last[a[j]]=len;
					}
					len=last[a[j]];
				}
				now[len]=a[j];
				last[a[j]]=len;
				len++;
	//			cout<<"+++\n"<<len<<"\n\n";
			}
			for(int ss=i;ss<len;ss++) ans[now[ss]]++;
	//		for(int ss=i;ss<len;ss++) cout<<now[ss]<<" ";
	//		cout<<"\n\n---------"<<len<<"--------\n";
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			vector<int> last(m+10,-1),now(n*2+11,0);
			int len=i;
			for(int j=i;j<n;j++)
			{
				if(last[a[j]]!=-1)
				{
					for(int kkk=i;kkk<=len;kkk++)
					{
						if(a[j]==now[kkk])
						{
							len=kkk;
							break;
						}
					}
				}
				now[len]=a[j];
				last[a[j]]=len;
				len++;
	//			cout<<"+++\n"<<len<<"\n\n";
			}
			for(int ss=i;ss<len;ss++) ans[now[ss]]++;
	//		for(int ss=i;ss<len;ss++) cout<<now[ss]<<" ";
	//		cout<<"\n\n---------"<<len<<"--------\n";
		}
	}
	ans[a[n]]=n;
	for(auto it:ans) cout<<it<<" ";
	return 0;
}
