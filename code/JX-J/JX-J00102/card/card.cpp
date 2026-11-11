#include <bits/stdc++.h>
using namespace std;
int sfy(string a1,int b1)
{   for(int i=0;i<a1.size();i++)
    {   if(b1==a1[i]-48)
        {   return i;
        }
    }
    return -1;
}
string qc(string a2,int b2)
{   string c2="";
    for(int i=0;i<b2;i++)
    {   c2+=a2[i];
    }
    return c2;
}
int jf(string a3,int b3)
{   for(int i=0;i<a3.size();i++)
    {   if(a3[i]-48==b3)
        {   return 1;
        }
    }
    return 0;
}
int main()
{   freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],d[500005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {   cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {   string b="";
        for(int j=i;j<=n;j++)
        {   if(sfy(b,a[j])!=-1)
            {   int c=sfy(b,a[j]);
                b=qc(b,c);
            }
            b+=(char)(a[j]+48);
        }
        for(int k=1;k<=m;k++)
        {   d[k]+=jf(b,k);
        }
    }
    for(int i=1;i<=m;i++)
    {   cout<<d[i]<<' ';
    }
    return 0;
}
