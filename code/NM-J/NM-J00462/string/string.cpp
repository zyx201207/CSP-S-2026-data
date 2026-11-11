#include<bits/stdc++.h>
char a[2000000005],b,c,d;
long long m,n,j,xy,xz;
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>m;
    j=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&n);
        scanf(" %c",&b);
        for(int i=j;i<=n;i++)
        {
           a[i]=b;
        }
        j+=n;
    }
    for(int i=j/2;i>=1;i--)
    {
        xy++;
        if(a[i]!=a[xy])
            xz++;
    }
    cout<<xz;
    return 0;
}
