#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010010],s=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    while(m>=s)
    {
        if(a[s]<a[s+1]&&m>=s)
        {
            a[s]+=1;
            m-=s;
        }
        else if(a[s]==a[s+1]&&m>=s+1)
        {
            s++;
            a[s]+=1;
            m-=s;
        }
    }
        if(a[s+1]==a[s])
        {
            s++;
        }
    cout<<s;
    return 0;
}