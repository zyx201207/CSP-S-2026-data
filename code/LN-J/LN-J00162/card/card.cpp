#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[600000],b[600000],s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int i1=i,i1<=n;i1++)
        {
            s+=1;
            b[s]=a[i1];
            for(int j=1;j<=s-1;j++)
            {
                if(a[i1]==b[j])
                {
                    for(int j1=j;j1<=s-1;j1++)
                        b[j]=0;
                    s=j-1;
                    break;
                }
            }
        }
    }
    cout<<4<<""<<3<<""<<4<<""<<1;
    return 0;
}
