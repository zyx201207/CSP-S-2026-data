#include <bits/stdc++.h>
using namespace std;
long long m[200005],sum;
char a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> m[i];
        cin >> a[i];
    }
    int i=1,j=n;
    while(i-j!=0){
        if (a[i]!=a[j] && (m[i]!=0 && m[j]!=0))
        {
            sum+=min(m[i],m[j]);
        }
        if(m[i]-m[j]>=0)
        {
            m[i]-=m[j];
            j--;
        }else{
            m[j]-=m[i];
            i++;
        }
    }
    cout << sum;
    return 0;
}
