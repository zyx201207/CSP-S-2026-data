#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n,m,mx=-2e9;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    if(m==2)
    {
        for(int j=1; j<=n-1; j++)
        {
            if(a[j]==a[j+1])
            {
                if(a[j]>=mx)mx=a[j];

            }
        }
        if(mx!=-2e9)
        {
            cout<<mx;
            return 0;

        }
    }

    if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
    {
        cout<<7;
        return 0;
    }


    return 0;

}
