#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000001];
int b[200o001];
int z=1,y;
int c;
char b;
bool e;
int main()
{
    freopen("string .in","r",stdin);
    freopen("string .out","w",stdout);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    y=0;
    for(int i=1;i<=n;i++)
    {
        if(z>y)
        {
            break;
        }
        if(c)
        {
            if(d!=b[y])
            {
                ans+=min(c,a[y]);
            }
            if(c>a[y])
            {
                c-=a[y];
                y--;
                coutinue;
            }
            c=0;
            a[y]-=c;
        }
        else
        {

        }
    }
    return 0;
}
