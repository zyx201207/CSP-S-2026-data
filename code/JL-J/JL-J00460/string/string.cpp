#include<bits/stdc++.h>
using namespace std;
long long n,sum,ans;
char C[5000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int a;
    char c;
    long long cnt=0,cn=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        cnt+=a;
        for(long long j=cn;j<=cnt;j++) C[j]=c;
        cn+=a;
    }
    for(int i=1;i<=cnt/2+1;i++)
    {
        if(C[i]!=C[cnt+1-i]) ans++;
    }
    cout<<ans;
    return 0;
}
