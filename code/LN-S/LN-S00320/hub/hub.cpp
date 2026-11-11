#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,k;
    int b;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        if(n%5==0)
        {
            b=n%5;
        }else
        {
            b=n%5+1;
        }
        cout<<b<<endl;
    }
    return 0;
}
