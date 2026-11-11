#include <bits/stdc++.h>
using namespace std;
string q,w;
long long a,b,sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>a;
    for(int i=1;i<=a;i++)
    {
        cin>>b;
        cin>>w;
        for(int j=1;j<=b;j++)
        {
            q+=w;
        }
    }
    int e=q.size();
    for(int i=0;i<e/2;i++)
    {
        if(q[i]!=q[e-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
