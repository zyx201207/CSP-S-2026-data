#include<bits/stdc++.h>
using namespace std;
bool d[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int a,b,c[500010],f[500010];
    auto<int>e;
    cin >> a >> b;
    for (int i = 1;i <= a;i++){
        cin >> c[i];
    }
    for (int i = 1;i <= a;i++){
        for (int j = i;j <= a;j++){
            if (d[c[j]]){
                while (!e.empty() && e.top() != c[j]){
                    d[e.top()] = false;
                    e.pop();
                }
                continue;
            }
            d[c[j]] = true;
            e.push(c[j]);
        }
        for (int j = 1;j <= a;j++){
            f[j] += d[j];
        }
    }
    for (int i = 1;i <= a;i++){
        cout << f[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
