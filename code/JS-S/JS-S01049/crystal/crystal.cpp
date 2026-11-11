#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500010];
bool AA = true;
long long ans = 0;
bool BB = true;
int c;
/*
struct box{
    long long val;
    long long cost;
} a[500010];

bool cmp(box a, box b) {
    return a.val < b.val;
}

void mix() {
    for(int i = 1; i <= n; i++) {
        if(a[i].val == a[i + 1].val) {
            a[i].cost
        }
    }
}
*/
long long slove(int l) {
    long long tmp = m;

        long long b[500010];
        for(int i = 1; i < l; i++) {
            b[i] = a[l] - a[i];
        }
        int t= l;
        while(tmp > 0 && t > 0) {
            tmp -= b[t];
            t--;
        }
        if(tmp < 0) t++;
        return l - t;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(a[i] != i) {
            AA = false;
        }
        if(i <= 2) {
            c = a[2] - a[1];
        } else {
            if(c != a[i] - a[i - 1]) {
                BB = false;
            }
        }
        //a[i].cost = 1; //how much mixed;
    }
    if(AA) {
        //cout<<"AA"<<endl;
        long long AAA = 1;
        while(m > 0){
            m -= AAA;
            AAA++;
        }
        if(m < 0) AAA--;
        cout<<AAA<<endl;
        return 0;
    }
    if(BB) {
        //cout<<"BB"<<endl;
        long long BBB = c;
        while(m > 0) {
            m -= BBB;
            BBB += c;
            ans++;
        }
        if(m < 0) ans--;
        cout<<ans<<endl;
        return 0;
    }
    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; i++) {
        long long tt = slove(i);
        ans = max (ans, tt);
        if(a[i] == a[i + 1]) {
            ans = max(ans, tt+1);
            i++;
        }
    }
    //mix();
    cout<<ans<<endl;
    return 0;
}
