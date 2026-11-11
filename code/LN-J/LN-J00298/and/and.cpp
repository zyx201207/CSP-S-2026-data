#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
bool comp(int a,int b)
{
    if(a>b)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1,comp);
    int jsq=arr[1];
    for(int i=2;i<=m;i++)
    {
        jsq=jsq&arr[i];
    }
    cout<<jsq;
    return 0;
}
