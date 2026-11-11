#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],z,b[500001],c,t,d[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++){
        c = 0;
        for(int j = i;j <= n;j++){
            t = 0;
            for(int k = 1;k <= c;k++)
                if(a[j] == b[k])
                   t = 1;
            if(t)
                c = 0;
            c++;
            b[c] = a[j];
        }
        for(int j = 1;j <= c;j++)
            d[b[j]]++;
    }
    for(int i = 1;i <= m;i++)
        cout << d[i] << ' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
