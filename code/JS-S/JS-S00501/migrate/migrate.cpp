#include<bits/stdc++.h>
using namespace std;

int c;

long long n;long long d;
long long x[2000010];

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(c==0||c==11||c==12){
        long long t=d/(x[2]-x[1]);
        if(t<=1){
            cout<<0<<'\n';
            return ;
        }
        long long sum=0;
        for(long long i=t+2;i<=min(2*t,n);i++){
            sum+=n-i+1;
        }
        cout<<sum<<'\n';
    }
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>c>>T;
    while(T--){
        solve();
    }

    return 0;
}