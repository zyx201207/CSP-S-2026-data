#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],l[200005],ans;
string op[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int s=a[i];
        while(s>0)
        {
            int t=s%2;
            op[i]+=to_string(t);
            s/=2;
        }
        l[i]=op[i].size();
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        cout<<ans;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
            {
                long long sum=0;
                for(int k=1;k<=min(l[i],l[j]);k++)
                {
                    if(op[i][k]==op[j][k])sum++;
                }
                ans=max(ans,sum);
            }
        cout<<ans;
    }
    else cout<<0;
    return 0;
}
