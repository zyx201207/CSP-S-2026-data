#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int num_1,num_2;
void ans_1() {
    for (int i=1 ; i<=n ; i++) {
        if (a[i]==1) {
            num_1+=1;
        }
        else {
            num_2+=1;
        }
    }
    cout <<n-num_1<<n-num_2;
}

signed main() {
    cin >>n>>m;
    for (int i=1 ; i<=n ; i++) {
        cin >>a[i];
    }
    if (m==2) {
        ans_1();
    }
    freopen("card.in","r",stdin);
    freopen("card.in","r",stdout);
    return 0;
}
