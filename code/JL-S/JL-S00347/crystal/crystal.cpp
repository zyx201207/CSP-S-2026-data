#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500000],b[500000],cnt=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    for(int j=1;j<=m;j++)
    {
        a[0]++;
        if(a[0]==a[cnt])
        {
            cnt++;
            if((m-j)/2>=(a[cnt+1]-a[cnt]))
            {
                continue;
            }
            else
            {
                cout<<++cnt<<endl;
                return 0;
            }
        }
    }
}
