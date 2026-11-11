#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
const int N=2e5+10;
struct n2
{
    int a;
    char b;
}a[N];;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int len=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].b;
        len+=a[i].a;
    }
   // cout<<len<<ln;
    int l=1;int r=len;
    int i=1,j=n;
    int ans=0;
    while(true)
    {
        if(i>=j) break;
        //if(l>=len/2||r<=len/2) break;
        int x=a[i].a-a[j].a;
        //cout<<ans<<ln;
       // cout<<i<<" "<<j<<ln;
       // cout<<l<<" "<<r<<ln;
        //cout<<a[i].b<<" "<<a[j].b<<ln;
        //cout<<a[i].a<<" "<<a[j].a<<ln;
        if(a[i].b!=a[j].b)
        {
            //cout<<'a'<<ln;
            ans+=min(a[i].a,a[j].a);
        }
        if(x==0)
        {
            //cout<<'a'<<ln;
            i++;
            j--;
            l+=a[i].a;
            r-=a[j].a;
        }
        if(x<0)
        {
            //cout<<'b'<<ln;
            a[j].a-=a[i].a;
            l+=a[i].a;
            r-=a[i].a;
            i++;
        }
        if(x>0)
        {
            //cout<<'c'<<ln;
            //cout<<a[j].a<<ln;
            a[i].a-=a[j].a;
            l+=a[j].a;
            r-=a[j].a;
            j--;
        }
    }
    // cout<<ln;
    // cout<<l<<" "<<r<<ln;
    // cout<<i<<" "<<j<<ln;
    cout<<ans<<ln;
    return 0;
}
// diff true.out sting.out