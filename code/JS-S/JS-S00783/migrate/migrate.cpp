#include<bits/stdc++.h>
using namespace std;

int c,t;
int n;
long long d;
long long x[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        if(c==0||c==11||c==12){
            long long D=x[2]-x[1];
            if(d/D!=0&&d/D!=1)cout<<max((long long)0,n-d*2/D+1)<<endl;
            else cout<<0<<endl;

        }
    }
    return 0;
}
