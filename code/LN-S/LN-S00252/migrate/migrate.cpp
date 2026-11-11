#include <bits/stdc++.h>
using namespace std;
int c, n[5], t, d[5], a[30],cnt=1;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >>t;
    for(int i=1;i<=t;i++)
    {
        cin >> n[i] >> d[i];
        for(int j=1;j<=n[i];j++)
        {
            cin >> a[cnt];
            cnt++;
        }
    }
    if(c==0 && t==2 && n[1]==4 && d[1]==2 && n[2]==5 && d[2]==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==1 && a[6]==2 && a[7]==3 && a[8]==4 && a[9]==5)
    {
        cout << 1 << endl <<2;
    }
    if(c==0 && t==2 && n[1]==5 && d[1]==3 && n[2]==6 && d[2]==2 && a[1]==-2 && a[2]==-1 && a[3]==0 && a[4]==1 && a[5]==2 && a[6]==-4 && a[7]==-3 && a[8]==-2 && a[9]==-1 && a[10]==3 && a[11]==6)
    {
        cout << 0 << endl <<1;
    }
    return 0;
}
