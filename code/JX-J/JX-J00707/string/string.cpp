#include<bits/stdc++.h>
using namespace std;
long long n,cnt1,ans;
char s[100000005],fi[100000005],se[100000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j=cnt;j<cnt+a;j++)
        {
            s[j]=b;
        }
        cnt+=a;
    }
    int l=0,r=cnt-1;
    for(int i=0;i<cnt/2;i++)
    {
        if(s[l]!=s[r]) ans++;
        l++;
        r--;

    }
    cout<<ans;
    return 0;
}
