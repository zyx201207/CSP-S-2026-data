#include <bits/stdc++.h>
using namespace std;

int n, m;
int card[500010];
int sum[300010];
int mapp[300010];
vector <int> desk;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> card[i];
    }
    for(int i = 1;i <= n;i++)
    {
        desk.clear();
        for(int j = i;j <= n;j++)
        {
            if(mapp[card[j]] == 0)
            {
                desk.push_back(card[j]);
                mapp[card[j]]++;
            }else{
                int x = 0;
                for(;x < desk.size();x++)
                {
                    if(desk[x] == card[j])
                    {
                        break;
                    }
                }
                for(int y = desk.size()-1;y > x;y--)
                {
                    desk.pop_back();
                }
            }
        }
        for(int x = 1; x <= m;x++) mapp[x] = 0; 
        for(auto x : desk)
        {
            sum[x]++;
        }
    }
    for(int i = 1;i <= m;i++) cout << sum[i] << " ";
    cout << endl;
    return 0;
}