#include<bits/stdc++.h>
using namespace std;
int n;
long long l;
long long a[200005];
long long x[100000005];
unsigned long long ans=0;
string s,s_1;
string s_2;
int b=1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>s_1;
        if(i==1)
            s_2=s_1;
        if(s_1!=s_2)
            b=0;
        for(int j=l+1;j<=l+a[i];j++)
            x[j]=s_1[0]-96;
        l+=a[i];
    }
    if(b==1)
    {
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=(l/2);i++)
    {
        if(x[i]!=x[l-i+1])
            ans++;
    }
    cout<<ans;
    return 0;
}
