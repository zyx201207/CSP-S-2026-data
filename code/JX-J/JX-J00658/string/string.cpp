#include <bits/stdc++.h>
using namespace std;
int n,a[200001],cnt;
string s[200001];
int main()
{
    freopen("string.in","r",stdin);
    freoren("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        if(s[i]!=s[n])
        {
            n--;
            cnt++;
        }
        else n--;
    }
    cout<<cnt;
    return 0;
}
