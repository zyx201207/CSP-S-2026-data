#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[1000005];
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,b;
        cin>>n>>b;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(a[2]-a[1]<b) cout<<0;
        else cout<<2;
    }
    return 0;
}
//priority_queue<int,greater<int>,vector<int>> q;



