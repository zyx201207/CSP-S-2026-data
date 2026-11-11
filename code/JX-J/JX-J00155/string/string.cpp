#include<bits/stdc++.h>
using namespace std;
int b[200001];
char c[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie();
    bool flag=true,f;
    int n,i,w=0,u=0;
    string a;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>b[i];cin>>c[i];
        int t;
        t=b[i];
        if(i==1){t--;a=c[i];}
        while(t>0)
        {
            a+=c[i];t--;
        }
        if(i>=2)
        {
            if(b[i]!=b[i-1]||c[i]!=c[i-1])
            flag=false;
            else if(b[i]!=b[i-1])
            f=false;
            else if(b[i]==b[i-1])
                f=true;
        }
    }
    if(flag)
    {
           cout<<0;return 0;
    }
    if(f)
       {
            for(i=1;i<=n;i++)
    {
        if(c[i]!=c[n-i+1])
            u++;
    }cout<<u;return 0;
       }

    if(a.size()%2!=0)
    for(i=0;2*i<=a.size();i++)
    {
        if(a[i]!=a[a.size()-i-1])
            w++;
    }
    else
    {
        for(i=0;i*2+1<=a.size();i++)
            if(a[i]!=a[a.size()-i-1])
            w++;
    }
    cout<<w;
    return 0;
}
