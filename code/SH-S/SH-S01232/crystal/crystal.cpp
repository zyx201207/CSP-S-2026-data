#include <iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m; 
    cin>>n>>m;
    int s,l=1;
    int sum=0;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>s;
        a[i]=s;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i-1]>a[i])
        {
            int tmp=a[i-1];
            a[i-1]=a[i];
            a[i]=tmp;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]==a[i])
                {
                	l+=1;
                    continue;
                }
                else if(a[j]<a[i])
                {
                    sum=sum+a[i]-a[j];
                    
                    if(sum>m)
                    {
                        break;
                        
                    }
                    if(sum==m)
                    {
                    	l+=1;
                    	break;
					}
                    else{
                        l+=1;
                    }

                }
			}
			b[i]=l;
			l=1;
			sum=0;
		}
for(int k=0;k<=n;k++)
{

	for(int i=n-1;i>0;i--)
    {
        if(b[i-1]>b[i])
        {
            int tmp=b[i-1];
            b[i-1]=b[i];
            b[i]=tmp;
        }
       
    }
}
       cout<<b[n-1];


    return 0;
}
