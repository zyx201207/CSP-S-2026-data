#include<bits/stdc++.h>
using namespace std;
long long n,sum,d,v,k;
long long a[210000];
char s[210000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    v=n;
    for(int i=1;i<=v;i++)
    {
        while(a[i])
        {
            //cout<<i<<' '<<v<<endl;
            if(v<=0)break;
            if(a[i]>a[v])
            {
                a[i]-=a[v];
                if(s[i]!=s[v])sum+=a[v];
                s[v]=s[i];
                v--;
            }else
            {
                a[v]-=a[i];
                if(s[i]!=s[v])sum+=a[i];
                s[i]=s[v];
                break;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
