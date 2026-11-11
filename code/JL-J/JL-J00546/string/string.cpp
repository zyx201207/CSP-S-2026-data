#include <bits/stdc++.h>
using namespace std;
long long n,f[200001],ans;
char ch[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        cin>>ch[i];
    }
    for(int i=1,l=n;i<l;)
    {
        if(ch[i]==ch[l])
        {
            if(f[i]>f[l])
                f[i]-=f[l],l--;
            else if(f[i]==f[l])
                i++,l--;
            else
                f[l]-=f[i],i++;
        }
        else
        {
            if(f[i]>f[l])
                f[i]-=f[l],ans+=f[l],l--;
            else if(f[i]==f[l])
                ans+=f[l],i++,l--;
            else
                f[l]-=f[i],ans+=f[i],i++;
        }
    }
    cout<<ans;
    return 0;
}
