#include<bits/stdc++.h>
using namespace std;
int n,m,ct,a[200010],b[200010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);//xing zhi A
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1])
        {
            b[ct]=i;
        }
        else
        {
            ct++;
            b[ct]=i;
        }
    }
    for(int i=1;i<=ct;i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}
