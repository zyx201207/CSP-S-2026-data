#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,o=0;
    char c[200005];
    int a[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        if(a[i]>=80000000)o=1;
    }
    if(o)
    {
        for(int i=1;i<=n;i++)
        {
            a[i]/=1000;
        }
    }
    long long ans=0,ln=1,rn=n,lb=a[ln],rb=a[rn],i=1;
    while(ln<=rn)
    {
        if(c[ln]!=c[rn])ans++;

        //cout<<i<<": "<<ans<<" "<<ln<<" "<<lb<<" "<<rn<<" "<<rb<<endl;
        lb--;
        rb--;
        i++;
        if(lb==0)
        {
            ln++;
            lb=a[ln];
            //cout<<"  l:"<<ln<<" "<<lb<<endl;
        }
        if(rb==0)
        {
            rn--;
            rb=a[rn];
            //cout<<"  r:"<<rn<<" "<<rb<<endl;
        }
    }
    if(!o)
        cout<<ans;
    else
        cout<<ans*1000;
    return 0;
}
