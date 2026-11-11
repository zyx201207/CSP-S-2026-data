#include<bits/stdc++.h>
using namespace std;
int n,ans,nn,js[500010],qzh[500010];
long long m,a,b,shu[500010];
priority_queue<long long,vector<long long>,greater<long long> > pq;
int main()
 {
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	 scanf("%d%lld",&n,&m);
 	for(int i=1;i<=n;i++)
 	   {
 	   	scanf("%lld",&a);
 	   	pq.push(a);
	   } 
	shu[0]=1e18;
	for(int i=1;i<=n;i++)
	   {
	   	a=pq.top();
	   	pq.pop();
	   	if(a==shu[nn]) js[nn]++;
	   	  else {
	   	  	    nn++;
	   	  	    shu[nn]=a;
	   	  	    js[nn]=1;
			   }
		qzh[nn]=js[nn];
	   }
	for(int i=1;i<=nn;i++)
	   {
	   	qzh[i]+=qzh[i-1];
	   }
	for(int i=1;i<=nn;i++)
	   {
	   	if(qzh[i]<=ans) break;
	   	long long sum=m;
	   	int gs=js[i];
	   	for(int j=i-1;j>=1;j--)
	   	   {
	   	   	long long ji=1ll*js[j]*(shu[i]-shu[j]);
	   	   	if(sum>=ji) {
	   	   		         sum-=ji;
	   	   		         gs+=js[j];
				        }
			  else {
			  	    int l=0,r=js[j],findd=0;
			  	    while(l<=r)
			  	         {
			  	         	int mid=l+(r-l)/2;
			  	         	long long mmi=(long long) mid;
			  	         	if(mmi*(shu[i]-shu[j])<=sum) { 
			  	         	                              findd=mid;
			  	         	                              l=mid+1;
							                             }
							  else r=mid-1;
						 }
					gs+=findd;
					break;
			       }
		   }
		ans=max(ans,gs);
	   }
	printf("%d",ans);
	fclose(stdin);
 	fclose(stdout);
 	return 0;
 } 
