#include <bits/stdc++.h>
using namespace std;
long long z[300001],g[300001],l[500001];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[500001],li = 1,v = 1,k = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    while (v <= n){
        for (int i = v;i <= n;i++){
            if (z[a[i]] == 0){
                l[li] = a[i];
                li++;
                z[a[i]]++;
            }
            else {
                int j = li - 1;
                while (l[j] != a[i]){
                    k++;
                    l[j] = 0;
                    j--;
                }
                li -= k;
                k = 0;
            }
        }
        for (int i = 1;i < li;i++){
            g[l[i]]++;
            l[i] = 0;
        }
        v++;
        li = 1;
        for (int i = 0;i <= m;i++){
            z[i] = 0;
        }
        for (int i = 0;i <= n;i++){
            l[i] = 0;
        }
    }
    for (int i = 1;i <= m;i++){
        cout << g[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
}
