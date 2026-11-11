#include<bits/stdc++.h>
using namespace std;

int n,m,a[10005],b[100005],e[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    vector<int> c;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            if(b[a[j]] != 0)
            {
                int f = 0;
                for(int z = 0;z <= c.size()-1;z++)
                {
                    if(c[z] == a[j]) f = 1;
                    if(f){b[c[z]]--;c[z] = 0;}
                }
            }
            c.push_back(a[j]);
            b[a[j]]++;
        }
        for(int j = 1;j <= m;j++)
        {
            e[j] += b[j];
            cout << b[j] << endl;
            b[j] = 0;
        }
        c.clear();
    }
    for(int i = 1;i <= m;i++) cout << e[i] << ' ';
    return 0;
}
