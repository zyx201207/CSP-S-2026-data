#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    char c;
    int times;
} a[200005];

int n;
ll ans;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i].times >> a[i].c;
    }
    int head=1,tail=n;//point-to : current.
    while (head < tail) {
        int x = min(a[head].times,a[tail].times);
        if (a[head].c != a[tail].c) {
            ans+=x;
        }
        a[head].times -= x;
        a[tail].times -= x;
        if (a[head].times == 0) head++;
        if (a[tail].times == 0) tail--;
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
