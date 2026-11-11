#include<bits/stdc++.h>
using namespace std;
int n;
long long l[200005],a;
char c[200005];
int main()
{
    cin>>n;
    int x=n/2;
    for(int i=1;i<=n;i++) cin>>l[i]>>c[i];
    int i=1,j=n;
    if(n%2==0) int y=1;
    else int y=2;
    while(i!=n/2&&j!=n/2+y)
    {
        if(a<0)
        {
            a+=l[++i];
            int b=i;
        }
        else if(a>0)
        {
            a+=l[--j];
            int b=j
        }
        if(c[i]==c[j]) x-=l[b];
    }
    cout<<x
    return 0;
}
