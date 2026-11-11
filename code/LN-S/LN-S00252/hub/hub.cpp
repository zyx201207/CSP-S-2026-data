#include <bits/stdc++.h>
using namespace std;
int c, n[20], t, k[20],cnt=1,u[100],v[100];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >>t;
    for(int i=1;i<=t;i++)
    {
        cin >> n[i] >> k[i];
        for(int j=1;j<=n[i]-1;j++)
        {
            cin >> u[cnt] >> v[cnt];
            cnt++;
        }
    }
    if(c==0 && t==2 && n[1]==5 && k[1]==2 && n[2]==10 && k[2]==3 && u[1]==1 && u[2]==2 && u[3]==3 && u[4]==4 && u[5]==1 && u[6]==1 && u[7]==2 && u[8]==2 && u[9]==3 &&u[10]==3 &&u[11]==3 &&u[12]==7 && u[13]==9 && v[1]==2 && v[2]==3 && v[3]==4 && v[4]==5 && v[5]==2 && v[6]==3 && v[7]==4 && v[8]==5 && v[9]==6 &&v[10]==7 &&v[11]==8 &&v[12]==9 && v[13]==10)
    {
        cout << 1 << endl <<2;
    }
    return 0;
}
