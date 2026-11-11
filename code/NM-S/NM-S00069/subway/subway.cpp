#include <bits/stdc++.h>
using namespace std;
long c,n,m,d,q,l,r,sum;
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    vector<int> zhan(m+1);
    vector<vector<int> > che(n+1,vector<int> (m+1,0));
    for(int i=1;i<=m;i++) {
        cin >> zhan[i];
    }
    for(int i=1;i<=n;i++) {
            cin >> che[i][0];
        for(int j=1;j<=che[i][0];j++) {
            int k,t;
            cin >> k >> t;
            che[i][k]=t;
        }
    }
    while(q--) {
        cin >> l >> r;
        sum=LONG_MAX;
        for(int i=1;i<=n;i++) {
            if(che[i][l] && che[i][r]) {
                sum=min(sum,long(che[i][l]+che[i][r]+zhan[l]+zhan[r]));
            }
        }
        if(sum!=LLONG_MAX) {
            cout << sum << '\n';
            continue;
        } else {
            for(int i=1;i<=m;i++) {
                if(i==l || i==r) continue;
                for(int j=1;j<=n-1;j++) {
                    for(int k=j+1;k<=n;k++) {
                        if(che[j][l] && che[j][i] && che[k][i] && che[k][r]) {
                            sum=min(sum,(long)che[k][i]+che[j][i]+che[j][l]+che[k][r]+zhan[l]+zhan[r]);
                        }
                        if(che[k][l] && che[k][i] && che[j][i] && che[j][r]) {
                            sum=min(sum,(long)che[k][l]+che[j][r]+che[k][i]+che[j][i]+zhan[l]+zhan[r]);
                        }
                    }
                }
            }
            cout << sum << '\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
