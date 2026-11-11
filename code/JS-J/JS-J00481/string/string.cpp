#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,a[1001],s=0,k=0,sum=0,sum_true=0,sum2=0;
    char c[1001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i]==c[i+1]) s++;
        else {k++;a[i+1]=false;if(c[i]==c[i+1]) a[i]=false;a[i+1]=false;}
    }
    if(s==n-1) cout<<0;
    if(k==1) 
    {
        for(int i=1;i<=n;i++)
        {
            sum_true+=a[i];
        }
        int i=1;
        while(true)
        {
            sum=0;
            sum+=a[i];
            i++;
        }
        cout<<sum_true-sum;
    }
    if(k>1)
        cout<<a[1];
    return 0;
}