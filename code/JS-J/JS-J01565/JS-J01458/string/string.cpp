#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    char c;
    int pos;
};
node a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long len=0;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val>>a[i].c;
        for(int j=1;j<=a[i].val;j++)
        {
            s+=a[i].c;
        }
        len+=a[i].val;
    }
    if(n==1)
    {
        cout<<0<<"\n";
        return 0;
    }
    int l=0;
    int r=len-1;
    long long ans=0;
    while(l<=len/2)
    {
        if(s[l]!=s[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans<<"\n";
    return 0;
}

