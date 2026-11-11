#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i]>>s[i];
    int r=n;
    long long c=0;
    for(int i=1;i<r;i++)
    {
        while(a[i]>=a[r])
        {
            if(s[i]!=s[r])
                c+=a[r];
            a[i]-=a[r];
            r--;
            if(i==r)
                break;
        }
        if(a[i]<a[r]&&i!=r)
        {
            if(s[i]!=s[r])
            c+=a[i];
            s[r]-=s[i];
        }
    }
    cout<<c;
    return 0;
}
