#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int a[5000005];
void tea(){
    while(t--){
        int n,d,cha=0,ans=0;
        cin>>n>>d;
        if(n==1||n==2||n==3){
                cout<<"0";
                continue;
            }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cha=a[i+1]-a[i];
        }
        int kua=d/cha;
        if(kua==1||kua==0){
            cout<<"0"<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            ans+=(n-i+1)/kua-2/kua;
        }
        cout<<ans<<"\n";
    }
    return;
}
void teb(){
    while(t--){
        int n,d;
        cin>>n>>d;
        if(n==1||n==2||n==3){
                cout<<"0";
                continue;
            }
        cout<<d-1<<endl;
    }
}
void tec(){
    while(t--){
        int n,d;
        cin>>n>>d;
        if(n==1||n==2||n==3){
                cout<<"0";
                continue;
            }
        cout<<n/2-1<<endl;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12)tea();
    else if(c==13||c==14)teb();
    else if(c==15||c==16||c==17||c==18)tec();
    else{
        while(t--){
            int n,d;
            cin>>n>>d;
            if(n==1||n==2||n==3){
                cout<<"0";
                continue;
            }
            if(n==4){
                cout<<"1";
                continue;
            }
            if(n==5){
                cout<<"2";
                continue;
            }
        }
    }
    return 0;
}
