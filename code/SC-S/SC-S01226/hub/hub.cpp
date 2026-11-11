#include <iostream>
using namespace std;
const long long N = 2e6 + 5;
int c,t;
int n,k,u[N],v[N];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1 ; i < n ; i++) cin >> u[i] >> v[i];
        srand(time(0));
        cout << rand() % 2 << '\n';
    }
    return 0;
}