#include<bits/stdc++.h>
using namespace std;
#define long long
int a1[65],a2[65],a3[65],a4[65],e,f,g,h,o;
int x[200010],y[100010][2],p=0;
bool ad[200010]={0};
int a(int b,int c){
    e=1,h=1,f=0;
    for(int i=1;i<=65;i++)
    {
        a1[i]=0;
        a2[i]=0;
        a3[i]=0;
    }
    while(b!=0)
    {
        a1[e++]=b%2;
        b/=2;
    }
    while(c!=0)
    {
        a2[h++]=c%2;
        c/=2;
    }
    o=min(h,e);
    for(int i=1;i<=o;i++)
    {
        if(a1[i]==1&&a2[i]==1)
        {
            a3[i]=1;
        }
    }
    f=0;
    for(int i=o;i>=1;i--)
    {
        if(a3[i]==1)
        {
            g=1;
            for(int j=1;j<i;j++)
            {
                g*=2;
            }
            f+=g;
        }
    }
    return f;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("add.in","r",stdio);
    freopen("add.out","w",stdout);
    int n,m,q=0,s=0,p1=0,d3;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            q=a(x[i],x[j]);
            if(p1<q&&ad[i]==0)
            {
                p=q;
                d3=i;
            }
    }
    }
    ad[d3]=1;
    m--;
    while(m!=1){
        for(int i=1;i<=n;i++)
        {
                q=a(p1,x[i]);
                if(p<q&&ad[i]==0)
                {
                    p=q;
                    d3=i;
                }
        }
        m--;
        p1=p;
        ad[d3]=1;
    }
    cout<<p;
    return 0;
}

