
/*int main()
{
    int n;
    cin>>n;
    long long sum=0;
    string s;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
         sum+=a;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    string p=s;
    reverse(p.begin(),p.end());
    if(p==s)
    {
       cout << 0;
    }
    long long k=sum/2;
    long long ans=0;
    for(int i=0;i<=k;i++)
    {
        if(s[i]!=p[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    char c;
}s[200010];
int main()
{
    freopen("string,in","r",stdin);
    freopen("string out","w",stdout);
    int n;
    cin>>n;
    bool flag=1;
    cin>>s[1].a>>s[1].c;
    char p=s[1].c;
    for(int i=2;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
        if(s[i].c!=p) flag=0;
    }
    if(flag==1)
    {
        cout << 0;
        return 0;
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r)
    {
        if(s[r].c!=s[l].c)
        {
            ans+=min(s[l].a,s[r].a);
            if(s[r].a>s[l].a)
            {
                s[r].a=s[r].a-s[l].a;
                l++;
            }
            else if(s[r].a<s[l].a)
            {
                s[l].a-=s[r].a;
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}
