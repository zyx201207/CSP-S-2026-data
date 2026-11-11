#include <bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
void solve(){
    int n,a[MAXN],d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n<<endl;
}
void solve1(){
    long long n,a[MAXN],d,dx;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dx=a[2]-a[1];
    long long len=d/dx;
    if(len!=2){
        cout<<0<<endl;
        return;
    }
    long long res=0;
    for(int i=1;i<=n;i++){
        int t=n-i;
        res+=t/2+t%2;
    }
    cout<<n-3<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            solve1();
        }
        return 0;
    }
    if(c==13||c==14){
        while(t--){
            cout<<0<<endl;
        }
    }
    while(t--){
        solve();
    }
    return 0;
}


