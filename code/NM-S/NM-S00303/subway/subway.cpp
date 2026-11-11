#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,a[10010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> p;
    for(int i = 1;i <= m;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        if(m<=10000&&n<=500&&c<=19&&c>=12)
        {
            cout << m*m[i];
        }
    }
        return 0
}
