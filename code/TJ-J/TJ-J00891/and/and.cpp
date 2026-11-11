#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200010];
int maxn=-1;
int max_1=-1;
int max_2=-1;
int num=0;
int num_1=0;
void ans_2() {
    for (int i=1 ; i<=n ; i++) {
        if (a[i]>maxn) {
            maxn=a[i];
        }

    }
    cout <<maxn;
}
void ans_3() {
    num=a[1];
    for (int i=2 ; i<=n ; i++) {
        num&=a[i];
    }
    cout <<num;
}
void ans_4() {
    for (int i=1 ; i<=n ; i++) {
        for (int j=i+1 ; j<=n ; j++) {
            if (i&j>max_1) {
                max_1=i&j;
            }
        }
    }
    cout <<max_1;
}
void ans_5() {
    for (int i=1 ; i<=n ; i++) {
            if (i==1) {
                num_1=a[2];
                for (int j=3 ; j<=n ; j++) {
                    num_1&=a[j];
                }
                if (num_1>max_2) {
                    max_2=num_1;
                }
            }
            else {
                num_1=a[1];
                for (int j=2 ; j<=n ; j++) {
                    if (i==j) {
                        continue;
                    }
                    else {
                        num_1&=a[j];
                    }
                }
                if (num_1>max_2) {
                    max_2=num_1;
                }
            }
    }
    cout <<max_2;
}

signed main() {
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
    cin >>n>>m;
    for (int i=1 ; i<=n ; i++) {
        cin >>a[i];
    }
    if (m==1) {
        ans_2();
    }
    if (m==2) {
        ans_4();
    }
    if (m==n) {
        ans_3();
    }
    if (m==n-1) {
        ans_5();
    }
    return 0;
}
