#include<bits/stdc++.h>
using namespace std;

long long n,d,a[2000006];

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    srand((unsigned)clock());
    while(t--)
    {
        cin>>n>>d;
        cout<<rand()%(n-1)<<endl;
    }
    return 0;
}
