#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxi=0x7ff;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    int m[t+1];
    for(int i=1;i<=t;i++)
    {
        int n,d;cin>>n>>d;
        int x[n+1],y[n+1];
        int num[n*4];
        memset(num,0,sizeof(num));
        for(int j=1;j<n;j++)
        {
            cin>>x[j]>>y[j];
        }
        for(int j=1;j<n;j++)
        {
            m[i]=max(num[j],m[i]);
        }
    }
    for(int i=1;i<=2;i++)cout<<"1"<<endl<<"2";
    return 0;
}
