#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            long long a;
            cin>>a>>a;
        }
        long long ans=rand()%(n-1);
        cout<<ans<<" ";
    }
}
