#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++){
            if(a[i]&a[j]>=maxn)
            {
                maxn=a[i]&a[j];
            }
        }

    }
    cout<<maxn;
    return 0;
}

