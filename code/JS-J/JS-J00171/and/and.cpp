#include<bits/stdc++.h>
using namespace std;
long long num[10000005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    sort(num,num+n+1);
    cout<<num[n-m+1];
    return 0;
}
