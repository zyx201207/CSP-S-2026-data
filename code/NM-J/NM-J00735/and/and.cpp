#include <bits/stdc++.h>
using namespace std;
int N = 100;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s,cnt[N], ant[N];
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        cin >> cnt[i];
        for (int j = 0;j<=n;j++){
            if (cnt[j] > cnt[i]){
                cout << ant[j];
            }else{
                ant[j] = cnt[j];
                cout << ant[j];
            }
        }
    }
}
