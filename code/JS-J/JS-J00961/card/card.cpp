#include <bits/stdc++.h>
using namespace std;
int n,m;
const int M=3e5+5;
int P[M];
bool F[M];
int Ans[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> P[i];
        if(F[P[i]])F[P[i]]=0;
        for(int i=1;i<=m;i++)
        {
            Ans[i]+=F[i];
        }
    }
    for(int i=1;i<=m;i++)cout << Ans[i] << ' ';
    return 0;
}
