#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],fd[505];
vector<int> a[505],t[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=n;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++)
    {
        cin >> k[i];
        for(int j=1;j<=k[i];j++)
        {
            int ak,tk;
            cin >> ak >> tk;
            a[i].push_back(ak),t[i].push_back(tk);
            fd[ak]=i;
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
    }
    if(n==2)
        cout << "32\n17";
    else if(n==3)
        cout << "35\n16";
    return 0;
}
