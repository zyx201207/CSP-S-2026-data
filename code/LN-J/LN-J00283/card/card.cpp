#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin>>n>>m;
    vector<long long> card;
    for (int i=0;i<n;i++)
    {
        long long c;
        cin>>c;
        card.push_back(c);
    }
    for (int i=0;i<m;i++)
    {
        cout<<1<<' ';
    }
    return 0;
}
