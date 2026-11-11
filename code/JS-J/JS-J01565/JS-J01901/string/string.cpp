#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],b[N],ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s;
        b[i]=s[0]-'a';
    }
    for(int lt=1,rt=n;lt<rt;)
    {
        if(b[lt]==b[rt])
        {
            if(a[lt]>a[rt]) a[lt]-=a[rt],rt--;
            else if(a[lt]==a[rt]) lt++,rt--;
            else a[rt]-=a[lt],lt++;
        }
        else
        {
            ans+=min(a[lt],a[rt]);
            if(a[lt]>a[rt]) a[lt]-=a[rt],rt--;
            else if(a[lt]==a[rt]) lt++,rt--;
            else a[rt]-=a[lt],lt++;
        }
    }
    cout<<ans;
    return 0;
}
