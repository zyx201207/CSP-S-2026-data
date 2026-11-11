#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5000005];
struct point
{
    int x;
    int next=0;
}arr[5000005];
int ap[5000005]={0};
int ans[5000005]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=n;i>=1;i--)
    {

        arr[i].x=i;
        arr[i].next=ap[a[i]];
        ap[a[i]]=i;

        for(int j=i;j<=n;j++)
        {
            if(arr[j].next==0)
            {
                ans[a[j]]++;
            }
            else
            {
                j=arr[arr[j].next].x-1;
            }
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
