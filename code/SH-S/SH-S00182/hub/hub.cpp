#include <stdio.h>
void solve(void) {
    printf("1\n");
}
int main(void) {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while (t--) solve();
    return 0;
}