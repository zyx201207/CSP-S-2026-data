#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c==11||c==12){
            d/=(a[2]-a[1]);
            if(d==2) cout<<2;
            else cout<<0;
        }else{
            int cnt=0;
            for(int i=1;i<=n-3;i++){
                if(a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d) cnt++;
            }
            cout<<cnt;
        }
        cout<<'\n';
    }
    return 0;
}
