#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;
int c,t,n,k;
vector<vector<int>> a;
int s[20][20];
int ss[20][20];
int dd(int u,int v)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(ss[u][i]==1)
		{
			if(i==v) return ++cnt;
			ss[u][i]=0;
			ss[i][u]=0;
			if(cnt==0) cnt=dd(i,v);
			else cnt=min(cnt,dd(i,v)+1);
		}
	}
	return cnt;
}
int d(int u,int v)
{
	int cnt=0;
	if(u==v) return 0; 
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=12;j++){
			ss[i][j]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ss[u][i]==1)
		{
			if(i==v) return ++cnt;
			ss[u][i]=0;
			ss[i][u]=0;
			if(cnt==0) cnt=dd(i,v);
			else cnt=min(cnt,dd(i,v)+1);
		}
	}
	return cnt;
}
int ff(int aa,int ab,int ac)
{
	return (s[aa][ab]||s[aa][ac]||s[ab][ac]);
}
int fff(int aa,int ab,int ac,int ad)
{
	return min(1,(s[aa][ab]+s[aa][ac]+s[ab][ac]+s[ad][aa]+s[ad][ab]+s[ad][ac]-1));
}
int ffff(int aa,int ab,int ac,int ad,int ae)
{
	return min(1,(s[aa][ab]+s[aa][ac]+s[ab][ac]+s[ad][aa]+s[ad][ab]+s[ad][ac]-2+s[ae][aa]+s[ae][ab]+s[ae][ac]+s[ae][ad]));
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		a.clear();
		for(int i=1;i<=12;i++) for(int j=1;j<=12;j++) 
		{
			if(i==j) s[i][j]=1;
			else s[i][j]=0;
		}
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			s[u][v]=1;
			s[v][u]=1;
		}
		int ans=1000000;
		if(k==2){
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int anss=0;
					for(int w=1;w<=n;w++) anss=max(anss,min(d(w,i),d(w,j)));
					ans=min(ans,anss);
				}
			}
		}
		if(k==3){
			for(int i=1;i<=n;i++) for(int q=1+i;q<=n;q++)
				for(int j=q+1;j<=n;j++)
				{
					if(!ff(i,q,j)) continue;
					int anss=0;
					for(int w=1;w<=n;w++) {
						anss=max(anss,min(min(d(w,i),d(w,j)),d(w,q) ) );
						
					}
					ans=min(ans,anss);
				}
		}
		if(k==4){
			for(int i=1;i<=n;i++) for(int q=i+1;q<=n;q++) for(int e=q+1;e<=n;e++)
				for(int j=e+1;j<=n;j++)
				{
					if(!fff(i,q,j,e)) continue;
					int anss=0;
					for(int w=1;w<=n;w++) anss=max(anss,min(d(w,e),min(min(d(w,i),d(w,j)),d(w,q) ) ));
					ans=min(ans,anss);
				}
		}
		if(k==5){
			for(int i=1;i<=n;i++) for(int q=1+i;q<=n;q++) for(int e=1+q;e<=n;e++) for(int f=1+e;f<=n;f++)
				for(int j=f+1;j<=n;j++)
				{
					if(!ffff(i,q,j,e,f)) continue;
					int anss=0;
					for(int w=1;w<=n;w++) anss=max(anss,min(d(w,f),min(d(w,e),min(min(d(w,i),d(w,j)),d(w,q) ) )));
					ans=min(ans,anss);
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
