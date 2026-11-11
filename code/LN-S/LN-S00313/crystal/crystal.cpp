#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int op=5e5+5;
ll a_max=0,a=0,b[op],c[op],n,ant=0;
 long long m;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    /* int ant=0;
    int i;
    for(i=5000;i>0;i--)
        ant+=i;
    cout<<ant;*/
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {

        cin>>c[i];}
        sort(c+1,c+n+1);
    for(long long i=1;i<=n;i++)
    {


        b[i]=a*(c[i]-c[i-1])+b[i-1];
        while(b[i]>m)
        {
            b[i]=b[i]-(c[i]-c[++ant]);
            a--;
            cout<<b[i]<<' '<<a<<' ';
        }

        a++;
        a_max=max(a_max,a);


    }
    cout<<a_max;
    return 0;
}
