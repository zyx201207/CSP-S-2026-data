#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,sum=0,l;
int a[200005];
char c[200005];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        l+=a[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    int k=l/2;
    for(int i=0;i<k;i++)
    {
        if(s[i]!=s[l-i-1])
            sum++;
    }
    cout<<s<<' '<<sum;
    return 0;
}
