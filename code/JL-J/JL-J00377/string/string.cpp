#include<bits/stdc++.h>
using namespace std;
string m,c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,s=0,ans=0;
    string b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            m.append(b);
            c.append(b);
            s++;
        }
    }
        for(int i=0;i<s/2;i++)
        {
            if(m[i]!=m[s-i-1])
            {
                ans++;
            }
        }

    cout<<ans;
    return 0;
}
