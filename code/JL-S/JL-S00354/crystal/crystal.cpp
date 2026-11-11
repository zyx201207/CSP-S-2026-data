#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    int a[n]={0},j=0;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
    {
        if (a[j]==a[j+1])
            a[j+1]+=a[j];
        if (a[j]+i==a[j+1]){
            a[j+1]+=(a[j]+i);
            m-=i;
            sum+=i;
            if (m==0)
                break;
        }
        j++;
    }
    cout<<sum;
    return 0;
}
