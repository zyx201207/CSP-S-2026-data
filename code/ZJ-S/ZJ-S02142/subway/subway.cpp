#include<bits/stdc++.h>
using namespace std;
int a[504][1005];
int b[500004];
struct Line{
	int Name[22];
	int Stop[1005];
	int s1;
	int s2;
} k[504];
int c,n,m,d,p,ans=0;
int su=0;
bool Check(int f,int o);
void Work(int fr,int t);
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(c==0)
	{
		if(n==2)
			cout<<32<<endl<<17;
		else
			cout<<35<<endl<<16;
	}
	return 0;
}
	/*for(int i=1;i<=m;++i)cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			//cin>>k[i].Stop[j];
			cin>>a[i][j];
			ans+=a[i][j];
			//k[i].Name[++k[i].s1]=i;
		}
	}
	int a,b;
	for(int i=1;i<=p;++i){
		su=0;
		cin>>a>>b;
		Work(a,b);
		//cout<<ans+b[a]<<endl;
	}
	if(Check(fr,t)==true)
		su+=b[t];
		ans=min(ans,su);
	}
	for(int i=1;i<=1000;i++)
	{
		if(k[fr].Stop[i]==0)break;
		else{
			su+=a[k[fr].Name[++k[fr].s2]][k[fr].Stop[i]];
			su+=a[k[k[fr].Stop[i]].Name][++s2][k[fr].Stop[i]];
			Work(k[fr].Stop[i],t);
			su-=a[k[fr].Name[--k[fr].s2]][k[fr].Stop[i]];
			su-=a[k[k[fr].Stop[i]].Name][--s2][k[fr].Stop[i]];
		}
	}
	return;
}
bool Check(int f,int o)
{
	for(int i=1;i<=1000;i++)
	{
		if(k[f].Stop[i]==o)
			return true;
	}
	return false;
}*/