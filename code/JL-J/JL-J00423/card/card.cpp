#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],h,s=1,b[10010],x,y,c,d;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    if(n<=10)
    {
        for(int i=1;i<=n;i++)
        {
            for(int l=1;l<=h;l++)
            b[l]=0;
            h=0;
            for(int f=i;f<=n;f++)
            {
                s=1;
                for(int j=1;j<=h;j++)
                {
                    if(b[j]==a[f])
                    {
                        s=0;
                        for(int k=j;k<=h;k++)
                        b[k]=0;
                        h=j;
                        b[h]=a[f];
                        break;
                    }
                }
                if(s==1)
                {
                    h++;
                    b[h]=a[f];
                }
            }
            c=1;d=1;
            if(m==2)
            {
                for(int v=1;v<=h;v++)
                {
                    if(b[v]==1&&c==1)
                    {
                        x++;
                        c=0;
                    }
                    if(b[v]==2&&d==1)
                    {
                        y++;
                        d=0;
                    }
                }
            }
        }
        cout<<x<<" "<<y;
    }

    return 0;
}
