#include <bits/stdc++.h>
using namespace std;
long long x[2000005]={0};
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;

    for (int i=0;i<t;i++)
    {

        int n=0;
        long long d=0;
        cin>>n>>d;
        for (int j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        long long cnt=0;
        for (int j=1;j<=n-3;j++)
        {

            if(x[j+2]-x[j]<=d&&x[j+3]-x[j+1]<=d)
            {
                cnt++;
            }

        }
        cout<<cnt<<endl;
    }
}
