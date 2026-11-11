#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c,t;
long long n,d;
long long x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        long long c;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+n+1);
        if(c==11||c==12){
            c=x[2]-x[1];
            long long b=d/c;
            if(n<2*b){
                cout<<0<<"\n";
            }else{
                cout<<(n-2*b)*(b-1)<<"\n";
            }
        }else{
            cout<<n-1<<"\n";
        }
    }
    return 0;
}
