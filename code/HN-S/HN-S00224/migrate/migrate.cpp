#include <bits/stdc++.h>
using namespace std;

const int mx=2*1e6+5;
int nrr[mx];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c,t;cin>>c>>t;
    while(t--){
        long long n,d,cnt=1;cin>>n>>d;
        for(int i=0;i<n;i++)cin>>nrr[i];
        for(int i=0;i<n;i++){
            int l=i+4;
            if(l<n)cnt++;
        }
        cout<<cnt<<'\n';
    }

    return 0;
}
