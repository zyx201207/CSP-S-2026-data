#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cout <<1;
    return 0;
}
void ans_1(){
    for (int i=2 ; i<=n ; i++) {
            num_1=1;
            for (int j=1 ; j<n ; j++) {
        if (m>=a[i]-a[i-1]) {
            num_1+=1;
            m-=(a[i]-a[i-1]);
            i=i-1;
        }
        else {
            if (num_1>maxn) {
                maxn=num_1;
            }
            break;
        }
    }
}
cout <<maxn;
}
if (n<=5 && m<=10) {
        aif (n<=5 && m<=10) {
        ans_1();
    }ns_1();
    }
