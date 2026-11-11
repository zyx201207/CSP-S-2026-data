#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    for(int i=1,j=n;i<j;)
    {
        if(c[i]!=c[j]) ans+=min(a[i],a[j]);
        if(a[i]<a[j])
        {
            a[j]-=a[i];
            i++;
        }
        else if(a[i]>a[j])
        {
            a[i]-=a[j];
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
    cout << ans;
    return 0;
}
