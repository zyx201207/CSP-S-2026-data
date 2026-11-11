#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long p[2000006];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    //假装这是暴戾语言
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                cin>>p[i];
            }
            int ccc=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+3;j<=n;j++)
                {
                    int cnt=0;
                    for(int k=i+1;k<j;k++)
                    {
                        if(p[k]-p[i]<=d&&p[j]-p[k]<=d)
                        {
                            cnt++;
                        }
                    }
                    if(cnt==2)
                    {
                        ccc+=1;
                    }
                }
                
            }
            cout<<ccc<<endl;
            for(int i=1;i<=n;i++)
            {
                p[i]=0;
            }
        }

    return 0;
}