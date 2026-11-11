#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for (int i=0;i<n;i++){
        int b;
        cin>>b;
        a.push_back(b);
    }
    int ans=0;
    for (int i=30;i>=0;i--){
        int cnt=0;
        for (int j=0;j<n;j++){
            if ((a[j]&ans)==ans && (a[j]&(1<<i))>0){
                cnt++;
            }
        }
        if (cnt>=m){
            ans|=(1<<i);
        }
    }
    cout<<ans;
    return 0;
}
