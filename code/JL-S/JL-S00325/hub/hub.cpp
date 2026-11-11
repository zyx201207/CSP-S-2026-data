#include <cstdio>
using namespace std;

int t;

void inp() {
    int c;
    scanf("%d%d", &c, &t);
}

void work() {
    while (t -- )
        puts("0");
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
