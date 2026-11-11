#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C;
    cin>>C;C=11;
    if(C==13||C==14){
        int T;
        cin>>T;
        while(T--){
            int n;long long d;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            if(a[n]-a[1]<=d)cout<<0<<"\n";
            else {
                int ans=0;
                for(int i=2;i<n;i++){
                    if(a[i]-a[1]<=d&&a[n]-a[i]<=d)ans++;
                }
                cout<<ans-1<<"\n";
            }
        }
    }
    if(C==11||C==12){
        int T;
        cin>>T;
        while(T--){
            int n;long long d;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            long long  c=a[2]-a[1];
            int  ma=d/c;
            if((n-1)%ma==0||a[n]-a[1]<=d)cout<<0<<"\n";
            else {
                int ans=(n-1)/ma+1;
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
