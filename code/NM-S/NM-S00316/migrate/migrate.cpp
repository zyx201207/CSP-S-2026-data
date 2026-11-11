#include<bits/stdc++.h>
using namespace std;
int c,t,n,cs[5005][5005];
long long d,x[5005],ans,jl[5005][5005];
vector<int> bian[5005],kong; 
struct node{
	        int qi,wz;
	        long long l;
           };
queue<node> q,kk;
int main()
 {
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	scanf("%d%d",&c,&t);
 	while(t--)
 	     {
 	     	q=kk;
 	     	ans=0;
 	     	for(int i=1;i<=n;i++)
 	     	   {
 	     	   	for(int j=1;j<=n;j++)
 	     	   	   {
 	     	   	   	jl[i][j]=jl[j][i]=2e18;
			  	   }
			   }
			scanf("%d%lld",&n,&d);
 	     	for(int i=1;i<=n;i++)
 	     	   {
 	     	   	bian[i]=kong;
 	     	   	scanf("%lld",&x[i]);
 	     	   	for(int j=i-1;j>=1;j--)
 	     	   	   {
 	     	   	   	if(x[i]-x[j]>d) break;
					bian[j].push_back(i);
			 	   }
			   }
			for(int i=1;i<=n;i++)
	           {
	   	        q.push({i,i,0});
	           }
	        while(q.empty()==false)
	             {
	              node topp=q.front();
		          q.pop();
		          if(jl[topp.qi][topp.wz]==topp.l) {
		          	                               cs[topp.qi][topp.wz]++;
				                                  } 
		          if(jl[topp.qi][topp.wz]>topp.l) {
		          	                               jl[topp.qi][topp.wz]=topp.l;
		          	                               cs[topp.qi][topp.wz]=1;
				                                  } 
				  int cc=bian[topp.qi].size();
				  for(int i=0;i<cc;i++)
				     {
				     	node asd;
				     	asd.qi=topp.qi;
				     	asd.wz=bian[topp.wz][i];
				     	asd.l=topp.l+1;
				     	q.push(asd);
					 }	
		         }
		    for(int i=1;i<=n;i++)
		       {
		       	for(int j=i+1;j<=n;j++)
		       	   {
		       	   	if(cs[i][j]==2) ans++;
				   }
			   }
			printf("%lld\n",ans);
		 }
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 } 
