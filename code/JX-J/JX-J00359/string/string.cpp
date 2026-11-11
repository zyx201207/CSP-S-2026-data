#include<bits/stdc++.h>
using namespace std;
int a[20005];
char b[20005];
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,nut=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(n<=1) cout<<0;
    b[0]=b[1];
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=b[i-1])
        {
            nut=1;
            break;

        }
    }
    if(nut==0) cout<<0;
    return 0;
}
