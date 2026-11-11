#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000],ans;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    return 0;
}



