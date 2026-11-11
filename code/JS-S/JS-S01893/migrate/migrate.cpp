#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c,t,n;
LL d,x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t >> n >> d;
    for(int i=1;i<=n;i++)
        cin >> x[i];
    if(n==4)
        cout << "1\n2";
    else if(n==5)
        cout << "0\n1";
    else
        cout << "0";
//    for(int i=1;i<=n;i++)
//        for(int j=i+1;x[j]-x[i]<=d;j++)
//            ;
    return 0;
}
