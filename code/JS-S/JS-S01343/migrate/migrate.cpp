#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int x[t];
    for(int i=1;i<=t;i++)
    {
        int n,d,cnt=0;
        cin>>n>>d;
        int b[n];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<i-1;j++)
            {
                if(b[i]-b[j]==d+1 and (b[i]-b[j])%2==1 and b[i]-b[j]>1 and i-j>1) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
