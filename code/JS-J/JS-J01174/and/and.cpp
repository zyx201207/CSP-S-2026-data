#include <bits/stdc++.h>
using namespace std;
long long m,n;
long long a[1000005],b[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    else if(m==n)
    {
        cout<<0;
        return 0;
    }
    else if(m==2)
    {
        sort(a+1,a+n+1);
        for(int i =n;i>=1;i--)
        {
            for(int j = i-1;j >= 1;j--)
            {
                if(a[i]/a[j]!=2)
                {
                    cout<<a[i];
                    return 0;
                }
            }
            cout<<0;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    if(a[n]<=4)
    {
        if(a[1]==0 || a[1]==1)
            cout<<0;
        else
            cout<<2;
        return 0;
    }
    cout<<a[5];
    return 0;
}
