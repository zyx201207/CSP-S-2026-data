#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long ans;
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=1,j=n;i<=j;)
    {
        if(i==j) break;
        if(c[i]==c[j])
        {
            if(a[i]>=a[j])
            {
                a[i]-=a[j];
                j--;
            }
            else
            {
                a[j]-=a[i];
                i++;
            }
        }
        else
        {
            if(a[i]>=a[j])
            {
                c[j]=c[i];
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }
            else
            {
                c[i]=c[j];
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
