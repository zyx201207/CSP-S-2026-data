#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int s[300005];
int st,se;
//kskbl zdjd?
int stop = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int r = 1;r <= n;r++){
        se = 0;
        for(int i = r;i <= n;i++){
            int ins = a[i];
            for(int j = se;j >= 1;j--){
                if(s[j] == ins){
                    se = j-1;
                    break;
                }
            }
            s[++se] = ins;
        }
        for(int i = 1;i <= se;i++){
            b[s[i]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << b[i];
        if(i != m) cout << ' ';
        else cout << '\n';
    }
    return 0;
}
