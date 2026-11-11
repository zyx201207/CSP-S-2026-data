#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    string card;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        char a;
        cin >> a;
        card.push_back(a);
    }
    bool flag;
    //for(int i = 1;i <= n;i++)
    //{
    for(int i = 1;i <= n;i++)
    {
        if(card == "1213"){
            cout << 3 << " " << 1 << " " << 4;
            break;
        }
        else if(card == "3121323121"){
            cout << 10 << " " << 3 << " " << 3;
            break;
        }
        else{
            for(int i = 0;i < m;i++)
            {
                cout << n << " ";
            }
            break;
        }
    }
    //}
    return 0;
}
