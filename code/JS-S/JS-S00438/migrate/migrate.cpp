#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005],dis[2000005];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //freopen("migrate3.in","w",stdin);      诈骗orz
    //freopen("migrtae.out","r",stdout);     诈骗orz
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        bool A=1,B=0,Bp=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])
            {
                A=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(x[i]-x[1]<=m&&x[n]-x[i]<=m)
            {
                B=1;
                Bp=i;
                break;
            }
        }
        if(!(A||B)&&n>5000)
        {
            cout<<"不会qwq"<<endl;
            continue;
        }
        //7~10不知道能不能过
        if(A)
        {
            int sx=x[1],gc=x[2]-x[1],tmp=0,di=0,ans=0;
            for(int i=1;i<=n;i++)
            {
                if(di<x[i])
                {
                    tmp+=(x[i]-tmp+d-1)/d*d;
                    di=x[i];
                    dis[i]=tmp;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;i*j<=x[n];j++)
                {
                    ;//不不不这无疑是困难的，不写了
                }
            }
            cout<<n*(n-1)/2<<endl;
        }
        if(B)
        {
            cout<<n-1+(Bp-1)*(Bp-2)/2+(n-Bp)*(n-Bp-1)/2<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int tmp=x[i],d1=0,d2=0;
                for(int k=i;k<=j;k++)
                {
                    if(x[k]>tmp)
                    {
                        tmp+=d;
                        d1++;
                    }
                }
                tmp=x[j];
                for(int k=j;k>=i;k--)
                {
                    if(x[k]<tmp)
                    {
                        tmp-=d;
                        d2++;
                    }
                }
                if(d1==d2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//uid:1419161
//orz kkk %%%
//orz chenzhe %%%
//orz chw %%%
//orz zgq %%%
//orz dzd %%%
//≈24 pts（可能会炸
//滚动的木头
//滚动的木头
//滚动的木头
//滚动的木头
//滚动的木头
