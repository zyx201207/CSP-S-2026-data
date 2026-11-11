#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],mi=100000010;
string c[1000010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        if(a[i]<mi)
        {
            mi=a[i];
        }
    }
    if(n==1)
    {
        cout<<0<<endl;
    }
    if(n==2)
    {
        cout<<min(a[0],a[1])<<endl;
    }
    else
    {
        cout<<mi<<endl;
    }
    return 0;
}
