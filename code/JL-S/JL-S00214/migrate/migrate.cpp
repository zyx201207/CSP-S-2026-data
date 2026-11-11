#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>t>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> a;
        for(int i=1;i<=n;i++){
            int m;
            cin>>m;
            a.push_back(m);
        }
        int x=a[1]-a[0];
        int y=d/x;
        y=min(y,n-1);
        x=y*(y-1)/2;
        cout<<x<<"\n";
    }
    return 0;
}
