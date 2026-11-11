#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    int a[200005];
    int w[2000006];
    int w1[2000006];
    cin>>c>>t;
    if(c==11|c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            if(abs(a[1]-a[2])>d){
                cout<<0;
                return 0;
            }
            else{
                if(d%abs(a[1]-a[2])){
                    cout<<n-d%abs(a[1]-a[2])-1;
                }
                else{
                    cout<<n-d%abs(a[1]-a[2]);
                }
            }
        }
    }
    else{
        while(t--){
            cin>>n>>d;
            long long sum=0;
            for(int i=1;i<=n;i++){
                cin>>a[i];
                sum+=a[i];
            }
            cout<<sum;
        }
    }
    return 0;
}
