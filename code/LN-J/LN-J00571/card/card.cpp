#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int st[500005];
int js[300005];
int zb[300005];
int t = 1;
int js1[300005];
int main (){
    freopen("card.in",'r',stdin);
    freopen("card.out",'w',stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];

    while (t <= n){
            int j = 1;
        for (int i = t;i <= n;i++){
            if (js[a[i]]+1 > 1){
                for (int p = zb[a[i]];p < i;p++){
                    js[st[p]]--;
                    zb[st[p]] = 0;
                    st[p] = 0;
                }
                js[i] = 0;
                st[i] = a[i];
            }
            st[i] = a[i];
            js[a[i]]++;
            zb[a[i]] = i;
        }
        for (int i = 1;i <= n;i++){
            if (js[i]){
                js1[i]+=js[i];
                js[i] = 0;
                zb[i] = 0;
            }
            st[i] = 0;
        }
        t++;
    }
    for (int i = 1;i <= n;i++){
        if (js1[i] == 0) continue;
        cout << js1[i] << " ";
    }

    return 0;
}
