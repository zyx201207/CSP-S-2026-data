#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m,ma=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>ma)
            ma=a[i];
        }
        cout<<ma;
    }
    if(m!=1)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }
    return 0;
}
