#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    fropen("and.in","r",stdin);
    fropen("and.out","w",stdout);
    vector<int>a(n);
    for (int i=0;i<n;i++)cin>>a[i];
    int mj=0;
    for (int b=30;b>=0;b--){
        int z=mj|(1<<b);
        int dick=0;
        for(int i=0;i<n;i++){
            if((a[i]&z)==z)dick++;
        }
        if (dick>=m)mj=z;
    }
    cout<<mj<<endl;
    return 0;
}
