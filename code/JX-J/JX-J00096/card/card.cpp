#include <iostream>
using namespace std;
int yq;
int main()
{

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long card[n+2];
    for(int i=0;i<=n;i++)
    {
        cin >> card[i];
    }
    card[n+1]=n;
    card[n+2]=m;
    for(int i=1;i<=m;i++)
    {
        cout << card[yq] << " ";
    }
    return 0;
}
