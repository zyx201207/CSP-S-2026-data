#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long a[100000],l[100000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a;
    int k=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int i=1;i<=m;i++)
        {
            a[i]+=1;
            l[i]=a[i];
            if(a[i]>l[i])
            {
                cout<<-1;
            }
            else
            {
                cout<<5;
            }

        }

    }
    return 0;
}
