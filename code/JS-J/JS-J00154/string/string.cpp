#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int n;
ll ts=0, changes=0;

struct ZippedString
{
    int num;
    char letter;
}zs[200005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> zs[i].num >> zs[i].letter;
        ts += zs[i].num;
    }
    int lx = 1, ly=1, rx=n, ry=zs[n].num; // lx -> left zs[lx] ly -> zs[lx].for(i) 
    while (lx <= rx)
    {
        if (lx >= rx && ly >= ry)
            break;
        //if (zs[lx].letter != zs[rx].letter) // index less, add 
        //{
        int restl = zs[lx].num - ly + 1, restr = ry;
        int minlr = min(restl, restr);
        ly += minlr;
        ry -= minlr;
        if (zs[lx].letter != zs[rx].letter)
            changes += minlr;
        if (ly > zs[lx].num)
        {
            lx ++;
            ly = 1;
        }
        if (ry < 1)
        {
            rx --;
            ry = zs[rx].num;
        }
        //}

        //printf("lx:%d ly:%d rx:%d ry:%d lchar:%c rchar:%c\n", lx, ly, rx, ry, zs[lx].letter, zs[rx].letter);
        // changes += (zs[lx].letter != zs[rx].letter);
    }
    cout << changes;
    return 0;
}
