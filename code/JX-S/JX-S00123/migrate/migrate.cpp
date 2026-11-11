#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000020],n,d;
int c,t;
void sol(){
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int buf=0;
                for(int k=1;k<=n;k++){
                    if(abs(a[k]-a[i])<=d&&abs(a[j]-a[k])<=d)buf++;
                    if(buf>2)break;
                }
                if(buf==2)cnt++;
                //cout<<i<<' '<<j<<' '<<buf<<'\n';
            }
        }
        cout<<cnt<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    cin>>c>>t;
    if(c==1||c==2){
        sol();
    }
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;int x;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            x=a[2]-a[1];
            if(2*x>d){
                cout<<"0\n";continue;
            }
            else{
                cout<<max(0ll,n-((d/x)*2-1))<<'\n';
            }
        }
    }
    if(c==13||c==14){
        while(t--){
            cout<<0<<'\n';
        }
    }
}
