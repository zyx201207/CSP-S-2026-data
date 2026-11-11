#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll shuijs,caozuos,zongxuqiu,zdsjs = 0;
ll nengliang[600005];
ll chazhi[600005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> shuijs;
    cin >> caozuos;
    zdsjs = 1;
    for(int i = 1;i<=shuijs;i++)
    {
        cin >> nengliang[i];
    }
    sort(nengliang+1,nengliang+shuijs+1);   
    for(int q = 1;q<=shuijs;q++)
    {
        chazhi[q] = nengliang[q] - nengliang[q-1];
    }
    for(int j = 1;j<shuijs;j++)
    {
        zongxuqiu += chazhi[j+1]*j;
        zdsjs += 1;
        if(caozuos<zongxuqiu)
        {
			zdsjs -= 1;
            break;
        }
    }
    cout << zdsjs;
    return 0;
}


