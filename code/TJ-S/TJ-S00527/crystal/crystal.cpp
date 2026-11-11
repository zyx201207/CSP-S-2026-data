#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int b[100010];
int num;
int maxn=-1;
int num_1=1;
void ans_7() {
    num=a[2]-a[1];
    m/=num;
    m*=2;
    for (int i=1; i<=n ; i++) {
        if (i*(i+1)>m) {
                if (i>=n) {
                    cout <<n;
                }
                else {
                    cout <<i;
                }
                return;
        }
    }
}
void ans_6() {
    m*=2;
    for (int i=1; i<=n ; i++) {
        if (i*(i+1)>m) {
                if (i>=n) {
                    cout <<n;
                }
                else {
                    cout <<i;
                }
                return;
        }
    }
}
bool h=false;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for (int i=1 ; i<=n ; i++) {
        cin >>a[i];
    }

    for (int i=1 ; i<=n ; i++) {
        if (a[i]!=i) {
            break;
        }
        if (i==n) {
            ans_6();
            h=true;
            break;
        }
    }
    for (int i=2 ; i<n ; i++) {
            if (h==true) {
                break;
            }
        if(a[i+1]-a[i]!=a[i]-a[i-1]) {
            break;
        }
        if (i==n-1) {
            ans_7();
            break;
        }
    }
    return 0;
}
