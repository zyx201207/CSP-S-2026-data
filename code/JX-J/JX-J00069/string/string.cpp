#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001]={},cnt=0,ans=0,cnt1[200001]={},cnt2[200001]={};
char c[200001]={};
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        cnt+=a[i];
        cnt1[i]=cnt1[i-1]+a[i];
    }
    cnt2[1]=cnt;
    for(int i=2;i<=n;i++)
    {
        cnt2[i]=cnt2[i-1]-a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt1[i]<=cnt/2)
        {
            for(int j=n;j>=i;j--)
            {
                if(cnt2[j]<=cnt1[i-1])
                {
                    continue;
                }
                if(c[i]!=c[j]&&cnt1[i]>=cnt2[j])
                {
                    ans+=a[j];
                }
                else if(c[i]!=c[j])
                {
                    ans+=a[j]-(cnt2[j]-cnt1[i]);
                }
                if(cnt2[j]>cnt1[i])
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
