#include<bits/stdc++.h>
using namespace std;
int L,S[105],n,m[105],sum=0;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n >> m[105];
    for(int i=1;i<=n;i++)
    {
        S[105] += m[i];
        if(S[i+1] != S[-i-1])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
