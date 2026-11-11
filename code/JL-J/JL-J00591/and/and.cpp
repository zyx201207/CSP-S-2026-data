#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long cnt=0,m,n,nowmax=-1,v[1000010];
    cin>>n>>m;
    cin>>v[0];
    cnt=v[0];
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>nowmax)
        {
            nowmax=v[i];
        }
        cnt&=v[i];
    }
    if(m==n)
    {
        cout<<cnt<<endl;
        return 0;
    }
    if(m==1)
    {
        cout<<nowmax<<endl;
        return 0;
    }

    return 0;
}
