#include<bits/stdc++.h>
using namespace std;
char w[2000005];
long long h[2000005];
long long n,z=0;
long long js[100000];
int cz(long long x)
{
    long long i=1;
    while(x>h[i])
    {
        x-=h[i];
        i++;
    }

    return i;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long l=0;

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];

        cin>>w[i];
        z+=h[i];
    }
    int pd=0;
    for(long long i=1;i<=z/2;i++)
    {
        if(w[cz(i)]!=w[cz(z+1-i)])
        {
            pd=1;
            js[1]++;
            if(js[1]>=10)
            {
                int lll=1;
                while(js[lll]>=10)
                {
                    js[lll]-=10;
                    js[lll+1]+=1;
                    lll++;
                }
            }
        }
    }
    long long u=1;
    if(pd==0)
    {
        cout<<0;
        return 0;
    }
    while(js[u]!=0)
    {
        u++;
    }
     while(u>1)
    {
        u--;
        cout<<js[u];

    }
    return 0;
}
