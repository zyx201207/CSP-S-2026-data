#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;

int a[500005];//a[i] ->第i张牌的点数
int eidx[300005];//edix[i] ->点数为i的牌最终落点
int leaves[300005];//leaves[i] ->留下了点数为i的牌的局数


int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        scanf("%d",a+i);
        eidx[a[i]] = max(eidx[a[i]],i);
    }

    for (int i=1;i<=n;i++) {
        int cur_pos = i;
        while (cur_pos <= n) {
            leaves[a[cur_pos]]++;
            if (eidx[a[cur_pos]]) cur_pos = eidx[a[cur_pos]];
            cur_pos++;
        }
    }
    for (int i=1;i<=m;i++) cout << leaves[i] << ' ';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
