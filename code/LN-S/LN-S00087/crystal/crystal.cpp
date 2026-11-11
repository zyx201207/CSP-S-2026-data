#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m,n;
ll psum[500005];
ll res[500005];

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> psum[i];

    sort(psum+1,psum+1+n);


    for (int i=1;i<=n;i++) {
        psum[i]+= psum[i-1];
    }
    bool exist = false;

    for (int i=1;i<=n;i++) {//length
        exist = false;
        for (int j=0;j+i<=n;j++) {//begin position ([j] [begin]...[begin+length-1 = j+length])
            ll sum = psum[j+i]-psum[j];
            ll maxv= psum[j+i]-psum[j+i-1];
            if (maxv*i-sum<=m) {
                exist = true;
                break;
            }
        }
        if (!exist) {
            cout << i-1;
            break;
        }
    }
    if (exist) cout << n;


    return 0;
}
