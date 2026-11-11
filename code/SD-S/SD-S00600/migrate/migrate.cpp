#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],yue,pp,lu[5001][5001],ans,lu2[5001][5001],l,r,zhong,zy[5001][5001],qian[5001][5001]; 
int main()
{
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=10)
	{
		for(int iii=1;iii<=t;iii++)
		{
			cin>>n>>d;
		    for(int i=1;i<=n;i++)
		    {
			    scanf("%lld",&a[i]);
		    }
		    ans=0;
		    for(int i=1;i<=n;i++)
		    {
		    	for(int j=1;j<=n;j++)
		    	{
		    		lu[i][j]=0;
		    		zy[i][j]=0;
		    		lu2[i][j]=0;
		    		zy[i][j]=0;
		    		qian[i][j]=0;
				}
			}
		    for(int i=1;i<=n;i++)
		    {
		    	lu[i][i]=1;
		    	qian[i][i]=1;
		    	zy[i][0]=i;
		    	for(int j=i+1;j<=n;j++)
		    	{
		    		l=i;
		            r=j-1;
		            if(a[j]-a[j-1]>d)
		            {
		            	break;
					}
		            while(l!=r)
		            {
			            if(l+1==r)
			            {
				            if(a[j]-a[l]<=d)
			                {
				                r=l;
			                }
			                else
			                {
				                l=r;
			                }
			            }
			            zhong=(l+r)/2;
			            if(a[j]-a[zhong]<=d)
			            {
				            r=zhong;
			            }
			            else
			            {
				            l=zhong;
			            }
		            }
		            lu2[i][j]=lu2[i][r]+1;
		            lu[i][j]=qian[i][zy[i][lu2[i][r]]]-qian[i][r-1];
		            zy[i][lu2[i][j]]=j;
		            qian[i][j]=qian[i][j-1]+lu[i][j];
		    		if(lu[i][j]==2)
		    		{
		    			ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	if(c==11||c==12)
	{
		for(int iii=1;iii<=t;iii++)
		{
			cin>>n>>d;
		    for(int i=1;i<=n;i++)
		    {
			    scanf("%lld",&a[i]);
		    }
		    yue=d/(a[n]-a[n-1]);
		    pp=0;
		    if(yue>1)printf("%lld\n",max(pp,n-(yue*2)+1));
		    else printf("0\n");
		}
    }
	return 0;
} 
