#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d,cnt=0;
        cin>>n>>d;
        bool x[1000005]={false};
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            x[a+N]=true;
        }
        for(int i=1;i<=n+N;i++)
        {
            if(x[i]==true&&x[i+(2*d)-1]==true&&x[i+d-1]==true&&x[i+d]==true)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
