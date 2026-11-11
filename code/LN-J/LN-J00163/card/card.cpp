#include <bits/stdc++.h>
using namespace std;
int table[500005];
int n,m,sum;
void op(int a){
    for (int i = 1;i <= sum;i++){
        if (table[i] == a){
            for (int j = i;j <= sum;j++){
                table[j] = 0;
                sum--;
            }
            break;
        }
    }
    table[++sum] = a;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int cards[500005],left[500005];
    for (int i = 1; i<= n;i++){
        cin >> cards[i];
    }
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            op(cards[j]);
        }
        for (int j = 1;j <= sum;j++){
            left[table[j]]++;
        }
        memset(table,0,sizeof(table));
    }
    for (int i = 1;i <= m;i++){
        cout << left[i] << " ";
    }
    return 0;
}
