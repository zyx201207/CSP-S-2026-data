#include<bits/stdc++.h>
using namespace std;
long long a[500005],r[500005];
const int N=1e12;
short b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans=0;
    unsigned long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
    sort(a+1,a+1+n);
    int mode=a[1];
    for(int i=2;i<=n;i++)
    {
        if (b[a[i]]>b[mode]) mode=a[i];
    }
    if(m==0) cout<<b[mode];
    else{
        int ans=b[mode];
        for(int i=1,j=1;i<=n;i++)
            if(b[a[i]]==b[mode]) r[j++]=a[i];
        for(int i=1,j=1;i<=n;i++)
            {
                mode=r[j++];
                bool q=1;
                while(a[i]!=mode)
                {
                    a[i]++; m--;
                    if(m==0){q=0; break;}
                }
                if(q) ans++;
                if(m==0) break;

            }
        cout<<ans;
    }
    return 0;
}
