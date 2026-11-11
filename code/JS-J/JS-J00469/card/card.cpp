#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
//Time that you hold deep inside your eyes
//Stories unfold from the path behind
//This life's a dream,I'll trace our years
//To leave our names,for all to hear
//When feathers fail,let our wings be twined
//We're meant for the sky that're unconfined
//When wind drops the burden wings sustain
//Yet time still I'll see you again
int a[500005],nxt[500005],ans[300005],nd[300005];
vector<int> vec[300005];
set<int> s,s2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		vec[a[i]].push_back(i);
		nd[i]=1;
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<vec[i].size();j++)
			nxt[vec[i][j]]=vec[i][vec[i].size()-1];
	for(int i=1;i<=n;i++)
	{
		nd[nxt[i]+1]+=nd[i];
		ans[a[i]]+=nd[i];
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
//Why I spend nearly 1 hour solving this problem?
//I am the king of Qu
//Oh,no!I'm undoubtfully angry because I only have 75mins for tetris
