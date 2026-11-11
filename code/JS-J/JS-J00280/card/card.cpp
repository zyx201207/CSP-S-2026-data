#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 4;
int n,m,a[N],stk[N],top,c[N];
bool have[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        top = 1;
        for (int j = 1;j <= n;j++) have[j] = 0;
        for (int j = i;j <= n;j++){
            if (have[a[j]]){
                while (top--){
                    have[stk[top]] = 0;
                    if (stk[top] == a[j]){
                        break;
                    }
                }
            }
            have[a[j]] = 1;
            stk[top] = a[j];
            top++;
        }
        for (int j = 1;j <= top - 1;j++){
            c[stk[j]]++;
        }
    }
    for (int i = 1;i <= m;i++){
        cout << c[i] << " ";
    }
    return 0;
}
