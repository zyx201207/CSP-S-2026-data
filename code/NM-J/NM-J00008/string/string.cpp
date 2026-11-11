#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long cnt=0;
char c[200010];
int main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<=j)
    {
        if(c[i]==c[j])
        {
            if(a[i]>a[j]) a[i]-=a[j];
            if(a[j]>a[i]) a[j]-=a[i];
        }
        else
        {
            if(a[i]==a[j]) cnt+=a[j];
            if(a[i]>a[j])
            {
                cnt+=a[i]-a[j];
                a[i]-=a[j];
                if(c[i+1]==c[i]) a[i+1]+=a[i];
                else if(c[i]==c[j-1]) a[j-1]-=a[i];
                else if(j-i!=1)
                {
                    cnt+=a[i];
                    a[j-1]-=a[i];
                }
            }
            if(a[j]>a[i])
            {
                cnt+=a[j]-a[i];
                a[j]-=a[i];
                if(c[j-1]==c[j]) a[j-1]+=a[j];
                else if(c[j]==c[i+1]) a[i+1]-=a[i];
                else if(j-i!=1)
                {
                    cnt+=a[j];
                    a[i+1]-=a[j];
                }
            }
        }
        i++,j--;
    }
    cout<<cnt;
    return 0;
}
