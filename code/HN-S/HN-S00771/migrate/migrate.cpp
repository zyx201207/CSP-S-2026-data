#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long c,T;
long long a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c==11||c==12){
        while(T--){
            long long ans=0;
            long long n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int s=a[2]-a[1];
            if(d/s<=1){
                cout<<"0\n";
                continue;
            }
            for(int i=1;i<=n;i++){
                if(i+d/s<n)ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}