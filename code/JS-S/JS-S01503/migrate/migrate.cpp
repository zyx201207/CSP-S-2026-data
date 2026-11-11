#include<bits/stdc++.h>;
using namespace std;
long long a[100005];
int main( )
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        int s=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int k=a[2]-a[1];
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if((a[j]-a[i])%d!=0&&(a[j]-a[i])>d)
                {
                    if((a[j]-a[i])%d==d-k)
                    {
                        s++;
                    }
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
