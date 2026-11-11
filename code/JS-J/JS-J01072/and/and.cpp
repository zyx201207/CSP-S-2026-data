#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
long long a[N];
long long n,m;
int ma,cntn[N][33];
bool backet[N];
long long l1[N];//daodijigeshi
void jisuan(long long x,int id2)
{

    int cnt=0;
    int jilu[34];
    for(int i=1;i<=33;i++)
    {
        jilu[i]=0;
    }
    while(x!=0)
    {
        cnt++;
        if(x&1)
        {
            l1[cnt]++;
            cntn[id2][cnt]=1;
        }
        x>>=1;
    }
    ma=max(ma,cnt);


    return;
}
void jianshao(int k)
{
    for(int i=32;i>=1;i--)
    {
        l1[i]-=cntn[k][i];
    }
    return;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        jisuan(a[i],i);
        backet[i]=1;
    }

    bool op=0;
    long long amns=n;
    for(int i=ma;i>=1;i--)
    {
        if(l1[i]>=m)
        {
            for(int it=1;it<=n;it++)
            {
                if(!backet[it])continue;
                if(cntn[it][i]==0)
                {
                    jianshao(it);
                    backet[it]=0;
                    amns--;
                }
                if(amns<=m)
                {
                    op=1;
                    break;
                }
            }
        }
        if(op)
        {
            break;
        }
    }
    int jishu=0;
    long long ans;

    for(int i=1;i<=n;i++)
    {
        if(backet[i])
        {
            if(jishu==0)
            {
                ans=a[i];
            }
            else
            {
                long long z;
                z=a[i]&ans;
                ans=z;
            }
            jishu++;

        }
        if(jishu==m)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
