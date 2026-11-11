#include <bits/stdc++.h>
using namespace std;
long long a, s, d[200001], ans = 0;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> a >> s;
    for (int i = 0; i < a; i++)
        cin >> d[i];
    for(int i=0;i<a;i++){
        for(int j=0;j<i;j++)
            if(ans<d[i]&d[j])ans=d[i]&d[j];
    }
    cout << ans << "\n";
}
