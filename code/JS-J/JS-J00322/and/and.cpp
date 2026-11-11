#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],q[2000005] = {},m1 = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        q[a[i]]++;
    }
    for(int i = 1;i <= n;i++){
        if((q[a[i]]) > 1){
            if(a[i] >= m1) m1 = a[i];
        }
    }
    cout << max(m1,0);
    return 0;
}
