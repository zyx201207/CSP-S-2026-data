#include<bits/stdc++.h>
using namespace std;
long long is[3000000];
long long d;
int n;
int pro(int x,int y)
{
    int key=0,now=x;
    for(int i=x+1;i<=y;i++)
    {
        while(is[i]-is[now]>d)
        {
            if(i-1==now)
            {
                return 0;
            }
            else
            {
                if((is[i-1]-is[now-1]<=d) && (now!=x))
                {
                    if((is[i-1]-is[now-2]<=d) && (now>x+1))
                    {
                        key++;
                    }
                    key++;
                }
                now=i-1;
            }
        }
        if(i==y)
        {
            //return now;
            if((is[y]-is[now-1]<=d) && (now!=x))
            {
                if((is[y]-is[now-2]<=d) && (now>x+1))
                {
                    key++;
                }
                key++;
            }
        }
    }
    if(key==1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>is[i];
        }
        for(int i=1;i<=n-3;i++)
        {
            for(int j=i+3;j<=n;j++)
            {
                ans+=pro(i,j);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}

