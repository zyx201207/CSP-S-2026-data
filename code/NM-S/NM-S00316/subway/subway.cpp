#include<bits/stdc++.h>
using namespace std;
const long long M=1e18;
struct node{
	        int zhong;
			long long quan;
			bool operator > (const node &a) const
			    {
			    	return quan>a.quan;
				}
           };
int c,n,m,d,q,k,x,y;
long long w[505],ans[505][505],anss;
bool sf[500505];
vector<node> bian[500505];
priority_queue<node,vector<node>,greater<node> > pq,kong; 
int main()
 {
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
 	for(int i=1;i<=m;i++)
 	   {
 	   	for(int j=1;j<=m;j++)
 	   	   {
 	   	   	if(i!=j) ans[i][j]=ans[j][i]=M;
		   }
	   }
 	for(int i=1;i<=m;i++)
 	   {
 	   	scanf("%lld",&w[i]);
	   }
	for(int i=1;i<=n;i++)
	   {
	   	scanf("%d",&k);
	   	for(int j=1;j<=k;j++)
	   	   {
	   	   	int sr1;
	   	   	long long sr2;
	   	   	scanf("%d%lld",&sr1,&sr2);
	   	   	bian[sr1].push_back({i+m,sr2});
	   	   	bian[i+m].push_back({sr1,sr2});
		   }
	   }
	for(int qwe=1;qwe<=q;qwe++)
	   {
	   	scanf("%d%d",&x,&y);
	   	if(ans[x][y]!=M) {
	   		              anss=ans[x][y]+w[x]+w[y];
						  printf("%lld\n",anss);
	   		              continue;
		                 }
		pq=kong;
		for(int i=1;i<=m;i++)
		   {
		   	if(i==x) { 
		   	          sf[i]=true;
		   	          pq.push({i,0});
		   	          continue;
			         }
			if(ans[x][i]!=M) {
				              sf[i]=true;
				              pq.push({i,ans[x][i]});
				              continue;
			                 }
		   	sf[i]=false;
		   }
		for(int i=m+1;i<=m+n;i++)
		   {
		   	sf[i]=false;
		   }
		while(pq.empty()==false)
		     {
		     	node topp=pq.top();
		     	pq.pop();
		     	ans[x][topp.zhong]=min(topp.quan,ans[x][topp.zhong]);
		     	ans[topp.zhong][x]=min(topp.quan,ans[topp.zhong][x]);
		     	int cc=bian[topp.zhong].size();
		     	for(int i=0;i<cc;i++)
		     	   {
		     	   	int e=bian[topp.zhong][i].zhong;
		     	   	if(sf[e]==true) continue;
		     	   	sf[e]=true;
		     	   	pq.push({e,topp.quan+bian[topp.zhong][i].quan});
				   }
			 }
		anss=ans[x][y]+w[x]+w[y];
		printf("%lld\n",anss);
	   }
	fclose(stdin);
 	fclose(stdout);
 	return 0;
 } 
