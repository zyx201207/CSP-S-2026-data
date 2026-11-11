#include<bits/stdc++.h>
using namespace std;

int a[500005],b[500005];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,cnt1 = 0,cnt2 = 0,cnt3 = 0;
    cin >> n >> m;
    int cnt0 = n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    while(cnt0 > 0) {
        for(int i = n-cnt0+1;i <= n;i++) {
            for(int j = n-cnt0;j < i;j++) {
                if(a[i] == a[j] && i != j && i != 0 && j != 0) {
                    break;
                } else {
                    if(a[i] == 1) {
                        cnt1++;
                    } else if (a[i] == 2) {
                        cnt2++;
                    } else {
                        cnt3++;
                    }
                }
            }
        cnt0--;
        }
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
    return 0;
}
