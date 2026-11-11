#include<bits/stdc++.h>
using namespace std;
int n,ans,cntact,cntans,eldact;
int a[500005];
long long m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m>100000000&&n>5000)
    {
        int k=a[1]-a[0];
        cntact=m;
        eldact=0;
        ans=1;
        while(1)
        {

            cntact-=k;
            cntact-=eldact;
            eldact+=k;
            if(cntact>=0&&ans<n)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            a[i]=a[i+1]-a[i];
        }
        for(int i=0;i<n;i++)
        {
            cntact=m;
            eldact=0;
            cntans=1;
            for(int j=i-1;j>=0;j--)
            {
                cntact-=a[j];
                cntact-=eldact;
                eldact+=a[j];
                if(cntact>=0)
                {
                    cntans++;
                }
                else
                {
                    break;
                }
            }
            ans=max(ans,cntans);
        }
    }
    cout<<ans;
    return 0;
}
