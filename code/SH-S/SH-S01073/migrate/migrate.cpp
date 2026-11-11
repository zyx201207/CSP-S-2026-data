#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e6+10;
LL x[MAXN],start[MAXN],fin[MAXN];
int ans[MAXN];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int t0=0;t0<t;t0++)
	{
		memset(ans,0,sizeof(ans));
		int n;
		LL d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		start[1]=1;
		fin[1]=n;
		for(int i=1;i<=n;i++)
		{
		    if(x[i+1]-x[i]>d)
		    {
		    	fin[i]=i;
		    	start[i+1]=i+1;
			}
		}
		int ANS=0,cnt=1;
		while(fin[cnt]!=0)
		{
		    for(int i=start[cnt];i<=fin[cnt];i++)
		    {   
			    for(int j=fin[cnt];j>i;j--)
			    {
			        if(x[j]-x[i]>d&&x[j]-x[i]-d<d) ans[cnt]++;
		    	}	
		    }
		    ANS=max(ANS,ans[cnt]);
		    cnt++;
		}
		cout<<ANS<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
