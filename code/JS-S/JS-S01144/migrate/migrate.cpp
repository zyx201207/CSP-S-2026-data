#include <bits/stdc++.h>
using namespace std;
vector<long long> pre;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        vector<long long> x;
        x.resize(n+5);
        pre.resize(n+5);
        for(int i=1;i<=n;i++){
            cin>>x[i];
            pre[i]=x[i]-x[i-1];
        }

        bool f1=1;
        int a=pre[1];
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(a!=pre[i]){
                f1=0;
            }
            sum+=pre[i];
        }
        if(f1==1){
            cout<<n/d;
            return 0;
        }
        else if(sum<=10*d){
            cout<<0;
            return 0;
        }

        cout<<(n-1)/d;
    }
    return 0;
}
