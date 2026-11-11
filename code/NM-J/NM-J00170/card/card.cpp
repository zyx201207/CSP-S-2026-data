#include<iostream>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int x[a],y[a],z[b],w[b];
    for(int i=0;i<a;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            y[j]=x[j+i];
        }
        for(int j=0;j<a-i;j++)
        {
            z[y[j]-1]+=1;
            for(int k=1;k<a-i;k++)
            {
                if(y[j]!=y[k])
                {
                    z[y[k]-1]+=1;
                    w[y[k]-1]=1;
                }
                else{
                    z[y[j]-1]=0;
                    for(int l=0;l<b;l++)
                    {
                        if(w[l]==1)
                        {
                            z[l]=0;
                            w[l]=0;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<b;i++)
    {
        cout<<z[i]<<" ";
    }
    return 0;
}