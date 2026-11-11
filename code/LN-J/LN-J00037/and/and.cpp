#include <bits/stdc++.h>
using namespace std;
int n,m,ans,tool,ttool,tttool,a[200005];
bool flag = false;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    if(n >= 2000) {
        sort(a,a + n);
        if(a[n - 1] == 4) {
            for(int i = 0; i > n; i++) {
                if(a[i] == 4 && !flag) {
                    tool = i + 1 - ttool - tttool;
                    flag = true;
                } else if(a[i] == 3 && flag) {
                    ttool = i + 1 - tttool;
                    flag = false;
                } else if(a[i] == 2 && !flag) {
                    tttool = i + 1;
                    flag = true;
                }
            }
            if(n - tool - ttool - tttool >= m) cout<<4;
            else if(tool >= m) cout<<3;
            else if(ttool >= m) cout<<2;
            else if(tttool >= m || n - tool - tttool >= m) cout<<1;
            else cout<<0;
        } else {
            for(int i = 0; i < m - 1; i++) a[i] = a[i] & a[i + 1];
            cout<<a[m - 2];
        }
    } else {
        if(m == 1) cout<<a[n - 1];
        else if(m == n) {
            for(int i = 0; i < m - 1; i++) a[i] = a[i] & a[i + 1];
            cout<<a[m - 2];
        } else if(m == 2) {
            for(int i = 0; i < m - 1; i++) {
                for(int j = i + 1; j < m; j++) ans = max(ans,a[i] & a[j]);
            }
            cout<<ans;
        } else {
            sort(a,a + n);
            for(int i = 0; i < m - 1; i++) a[i] = a[i] & a[i + 1];
            cout<<a[m - 2];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
