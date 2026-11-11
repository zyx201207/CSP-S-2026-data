#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
struct node{
	int to,next,len;
}a[N];
priority_queue< PII,vector<PII>,greater<PII> > q;
int c,n,m,d,k,qu,pre[N],da[N],w[N],r[N][30],le[N],kd[510],s,e;
bool f[N];
void add(int u,int v,int len)
{
	k++;
	a[k].to=v;
	a[k].next=pre[u];
	a[k].len=len;
	pre[u]=k;
}
bool findit(int x,int y)
{
	bool findx=false,findy=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=kd[i];j++)
		{
			if(r[j][i]==x) findx=true;
			if(r[j][i]==y) findy=true;
		}
		if(findx&&findy) break;
		findy=findx=false;
	}
	cout<<findx<<' '<<findy<<endl;
	if(findx&&findy) return true;
	else return false;
}
int main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin>>c>>n>>m>>d>>qu;
  for(int i=1;i<=m;i++) scanf("%d",&w[i]);
  for(int i=1;i<=n;i++)
  {
  	scanf("%d",&kd[i]);
  	for(int j=1;j<=kd[i];j++)
  	{
  		scanf("%d%d",&r[j][i],&le[j]);
  		if(j!=1)
  		{
  			//int len=le[j][i]+le[j-1][i];
  			add(r[j-1][i],r[j][i],(le[j]+le[j-1]));
  			add(r[j][i],r[j-1][i],(le[j]+le[j-1]));
		}
	}
  }
  for(int i=1;i<=qu;i++)
  {
  	scanf("%d%d",&s,&e);
  	memset(da,0x3f,sizeof(da));
  	memset(f,false,sizeof(f));
  	da[s]=0;
  	PII pe;
  	pe.first=0,pe.second=s;
  	q.push(pe);
  	while(!q.empty())
  	{
  		PII h=q.top();
  		int dis=h.first,p=h.second;
  		da[p]=dis;
  		q.pop();
  		if(e==p)
  		{
  			printf("%d\n",(da[e]+w[e]+w[s]));
  			break;
		}
		f[p]=true;
		//cout<<"kkk"<<endl;
		for(int j=pre[p];j;j=a[j].next)
		{
			//cout<<"t or f:"<<j<<endl;
			int to=a[j].to;
			if(!f[to]&&(dis+a[to].len)<da[to])
			{
				pe.first=(dis+a[to].len),pe.second=to;
				//if(findit(p,to)) pe.first-=a[to].len;
  				q.push(pe);
			}
		}
	}
  }
  return 0;
}


