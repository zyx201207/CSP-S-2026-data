#include<iostream>
#include<string>
#include<cstdio>
#define int long long
using namespace std;
int a[200005],c[200005];
string s;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,len=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>a[i]>>x;
        c[i]=x-'A'+1;
        len+=a[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=x;
        }
    }
    s=" "+s;
    int ans=0;
    int mid=(len+1)/2;
    for(int i=1;i<=mid;i++)
    {
        if(s[i]!=s[len-i+1])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
