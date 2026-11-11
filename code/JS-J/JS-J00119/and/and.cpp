#include<bits/stdc++.h>
using namespace std;

int a[2005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,Max=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    if(m=1)
    {
        cout << "0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int k=a[i]&a[j];
            Max=max(Max,k);
        }
    }
    cout << Max;
    return 0;
}
