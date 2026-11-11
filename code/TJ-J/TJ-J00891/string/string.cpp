#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node {
    int a;
    string c;
};
int an=1;
string q[100010];
node nu[200010];
int ans;
void num_1() {
    cout <<0;
}
void num_2() {
    if (nu[1].c==nu[2].c) {
        cout <<0;
    }
    else {
        if (nu[1].a>=nu[2].a) {
            cout <<nu[2].a;
        }
        else {
            cout <<nu[1].a;
        }
    }
}
void num_3() {
    for (int i=1 ; i<=n ; i++) {
        for (int j=1 ; j<=nu[i].a ; j++) {
            an+=1;
            q[an]=nu[i].c;
        }
    }
    for (int i=0 ; i<n/2 ; i++) {
        if (q[i]!=q[n-i]) {
            ans+=1;
        }
    }
    cout <<ans;
}

signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for (int i=1 ; i<=n ; i++) {
        cin >>nu[i].a>>nu[i].c;
    }
    if (n<=1) {
        num_1();
    }
     else if (n<=2) {
        num_2();
    }
    else {
        num_3();
    }
    return 0;
}
