#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long int x;
    char y;
};
node f[200005];
long long int n,flag,num,minn;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long int i=0;i<n;i++)
    {
        cin>>f[i].x>>f[i].y;
    }
    n--;
    while(1)
    {
        if(f[flag].y==f[n].y)
        {
            minn=min(f[flag].x,f[n].x);
            f[flag].x-=minn;
            if(f[flag].x==0)
                flag++;
            f[n].x-=minn;
            if(f[n].x==0)
                n--;
        }
        else
        {
            minn=min(f[flag].x,f[n].x);
            f[flag].x-=minn;
            if(f[flag].x==0)
                flag++;
            f[n].x-=minn;
            if(f[n].x==0)
                n--;
                num+=minn;
        }
        if(flag>=n)
            break;
    }
    cout<<num;
    return 0;
}
