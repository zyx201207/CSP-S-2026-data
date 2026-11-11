#include<bits/stdc++.h>
const double PI = 3.14159;
using namespace std;
long long  n,m,ans;
long long  num[200005];
bool check(long long  n1)
{
    long long  a1[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
    long long  i=0;
    for(long long  i=1;i<=18;i++)
    {
        if(a1[i]==n1) return true;
    }
    return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long  i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    ans=32767;
    long long  i=n,cnt=0;
    while(cnt!=m&&i>=1)
    {
        if(!check(num[i]))
        {
            cnt++;
            ans&=num[i];
        }
        i--;
    }
    cout<<ans;
    return 0;
}
