#include <bits/stdc++.h>
using namespace std;

int nc1 , nc2 , ns;
string c1 , s1 , c2 , s2;

int main() {
    freopen ("travel.in" , "r" , stdin);
    freopen ("travel.out" , "w" , stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool t = true;
    if (c1 == c2) printf ("1");
    else {
        printf ("0000");
        t = false;
        return 0;
    }
    ns = s1.size();
    for (int i=0; i<ns-1; i++) {
        if (s1[i] != s2[i]) {
            printf ("00");
            t = false;
            break;
        }
    }
    if (t == true) {
        printf ("1");
        int i = ns-1 , j = ns-1;
        if ((s1[i] == 'A' && s2[j] == 'B') || (s1[i] == 'B' && s2[j] == 'A') || (s1[i] == 'B' && s2[j] == 'C') || (s1[i] == 'C' && s2[j] == 'B') || (s1[i] == 'D' && s2[j] == 'F') || (s1[i] == 'F' && s2[j] == 'D')) {
            printf ("1");
        }
        else {
            if ((s1[i] == 'A' && s2[j] == 'C') || (s1[i] == 'C' && s2[j] == 'A')) printf ("1");
            else printf ("0");
            t = false;
        }
    }
    if (t == true) printf ("1");
    else printf ("0");
    return 0;
}
