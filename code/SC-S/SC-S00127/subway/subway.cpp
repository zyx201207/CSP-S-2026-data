#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=114514;
struct node{int line;int st_n;int tozhanting;};
struct noded{int now_line;int used_time;int goingtostation;};
int c,n,m,d,q,maxn=-0x3f3f3f3f;
int w[5*N];
bool book[5*N][555];
bool b[5*N];
vector<node>L[555];
vector<node>st[5*N];
//void bfs(int l,int r)
//{
//	queue<noded>nnext;
//	for(int i=0;i<st[l].size();i++) for(int j=0;j<L[st[l][i].line].size();j++) if((st[L[st[l][i].line][j].st_n].size()>=2 && !book[L[st[l][i].line][j].st_n][st[l][i].line]) || L[st[l][i].line][j].st_n==r) 
//	{
//		nnext.push({st[l][i].line,w[l]+st[l][i].tozhanting+L[st[l][i].line][j].tozhanting,L[st[l][i].line][j].st_n});
//	}
//	while(!nnext.empty())
//	{
//		noded p=nnext.front();nnext.pop();
//		if(book[p.goingtostation][p.now_line]) continue;
//		if(p.goingtostation==r)
//		{
//			for(int i=0;i<st[r].size();i++) if(st[r][i].line==p.now_line)
//			{
//				maxn=max(maxn,p.used_time+w[r]);
//				continue;
//			}
//		}
//		book[p.goingtostation][p.now_line]=true;
//		for(int i=0;i<st[p.goingtostation].size();i++) if(st[p.goingtostation][i].line!=p.now_line) for(int j=0;j<L[st[p.goingtostation][i].line].size();j++) if((st[L[st[p.goingtostation][i].line][j].st_n].size()>=2 && !book[L[st[p.goingtostation][i].line][j].st_n][st[p.goingtostation][i].line]) || L[st[p.goingtostation][i].line][j].st_n==r) nnext.push({st[p.goingtostation][i].line,p.used_time+L[st[p.goingtostation][i].line][j].tozhanting,L[st[p.goingtostation][i].line][j].st_n});
//	}
//}
void dfs(int l,int r,int used,int linee)
{
	if(l==r) 
	{
		maxn=max(used+w[r],maxn);
		return;
	}
	for(int i=0;i<st[l].size();i++) if(st[l][i].line!=linee) for(int j=0;j<L[st[l][i].line].size();j++) if((st[L[st[l][i].line][j].st_n].size()>=2 || L[st[l][i].line][j].st_n==r) && !b[L[st[l][i].line][j].st_n])
	{
		int xxxxx=L[st[l][i].line][j].st_n;
		b[xxxxx]=true;
		dfs(L[st[l][i].line][j].st_n,r,used+L[st[l][i].line][j].tozhanting,st[l][i].line);
		b[xxxxx]=false;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) 
	{
		int ki;scanf("%lld",&ki);
		for(int j=1;j<=ki;j++)
		{
			node xxx;
			xxx.line=i;scanf("%lld%lld",&xxx.st_n,&xxx.tozhanting);
			st[xxx.st_n].push_back(xxx),L[i].push_back(xxx);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;scanf("%lld%lld",&l,&r);maxn=-0x3f3f3f3f;memset(b,false,sizeof b);b[l]=true;
		for(int i=0;i<st[l].size();i++) for(int j=0;j<L[st[l][i].line].size();j++) if(st[L[st[l][i].line][j].st_n].size()>=2 || L[st[l][i].line][j].st_n==r)
		{
			b[L[st[l][i].line][j].st_n]=true;
			dfs(L[st[l][i].line][j].st_n,r,w[l]+st[l][i].tozhanting+L[st[l][i].line][j].tozhanting,st[l][i].line);
			b[L[st[l][i].line][j].st_n]=false;
		}
		printf("%lld",maxn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}