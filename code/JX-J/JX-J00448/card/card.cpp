#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],z[500005],c[300005],o[300005];//pd,zm,wz,cs
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            z[j]=a[j];
            if(c[a[j]]!=0)
            {
                for(int p=c[a[j]]+1;p<=j;p++)
                {
                    c[z[p]]=0;
                    z[p]=0;
                }
            }
            else{
                c[a[j]]=j;
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(z[j]!=0)
            {
                o[z[j]]++;
                z[j]=0;
            }
            c[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<o[i]<<" ";
    }
    return 0;
}
