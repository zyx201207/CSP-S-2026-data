#include <iostream>
#include <vector>
using namespace std;
int maxN = 5*100000 + 1;
int ans[maxN];
int table[maxN];
int card[maxN];
int main()
{
    freopen("/home/noi/桌面/kaoshi/TJ-J01486/card/card.in","r",stdin);
    freopen("/home/noi/桌面/kaoshi/TJ-J01486/card/card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> card[i];
    }
    sort(card, card+n);
    for(int i = 0;i < n;i++)
    {
        int tablelen = 0;
        int posFind[maxN] = {};
        for(int j = 0;j < n;j++)
            posFind[j] = -1;
        for(int j = i;j < n;j++)
        {
            if(posFind[card[j] != -1)
            {
                tablelen = posFind[card[j]]+1;
            }
            table[tablelen] = card[j];
            posFind[card[j] = tablelen;
            tablelen++;
        }
        for(int j = 0;j < tablelen;j++)
        {
ans[table[j]]++;
        }
    }
    for(int i = 0;i < n;i++)
    {
        cout << ans[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
