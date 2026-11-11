#include <bits/stdc++.h>
using namespace std;

int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    while(t--){
        long long n,d,cnt=0;
        long long x[2000005];
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d || x[j]-x[i]>2*d) continue;
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}
