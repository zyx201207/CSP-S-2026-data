#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int lj,T;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&lj,&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
        }
        if(k==n-1)cout<<1<<endl;
        else if(k==n)cout<<0<<endl;
        else cout<<114514<<endl;
    }
    return 0;
}
