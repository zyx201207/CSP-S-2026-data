#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
long long a[100000000];
int f(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    else{
        return 0;
    }

}
int main()
{
    freopen("and.in","r".stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,f);
    x=a[1];
    for(int i=2;i<=m;i++)
    {
        x&=a[i];
    }
    cout<<x;

    return 0;
}
