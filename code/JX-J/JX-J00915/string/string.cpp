#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n;
long long a[N],ans;
char c[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r)
    {
        if(c[l]!=c[r])
        {
            long long k=min(a[l],a[r]);
            ans+=k;
        }
        if(a[l]>a[r])
        {
            a[l]-=a[r];
            r--;
        }
        else if(a[l]==a[r])  l++,r--;
        else
        {
            a[r]-=a[l];
            l++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
