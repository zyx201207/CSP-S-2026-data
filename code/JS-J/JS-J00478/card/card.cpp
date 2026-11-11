#include<bits/stdc++.h>
using namespace std;

int n, m, cnt = 1;
int ap[300010], a[500010], wh[300010], g[500010];
bool num[300010];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    memset(ap, 0, sizeof(ap));
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i++){
        memset(num, false, sizeof(num));
        memset(wh, 0, sizeof(wh));
        memset(g, 0, sizeof(g));
        cnt = i;
        for(int j = i;j <= n;j++){
            if(num[a[j]] == false){
                //cout << "GO\n";
                g[cnt] = a[j];
                num[a[j]] = true;
                wh[a[j]] = cnt;
                cnt++;
            }
            else{
                for(int k = wh[a[j]] + 1;k <= cnt;k++){
                    num[g[k]] = false;
                    wh[g[k]] = 0;
                    g[k] = 0;
                }
                cnt = wh[a[j]];
                cnt++;
            }
            /*
            cout << "NUM:";
            for(int k = i;k <= cnt;k++){
                cout << g[k] << " ";
            }
            cout << endl;
            */
        }
        for(int j = i;j <= cnt;j++){
            ap[g[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ap[i] << " ";
    }
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/