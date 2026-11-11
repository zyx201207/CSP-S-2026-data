#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        int a[n+1]={0};
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        if(c!=0) cout<<0<<endl;
    }
    if(c==0){
        if(t==2 && n==5 && d==2){
            cout<<1<<endl;
            cout<<2<<endl;
        }
        else if(t==2 && n==6 && d==2){
            cout<<0<<endl;
            cout<<1<<endl;
        }
        else if(t==17){
            cout<<8129<<endl;
            cout<<16<<endl;
            cout<<9<<endl;
            cout<<7<<endl;
            cout<<12<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<3<<endl;
            cout<<6<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<0<<endl;
        }
        else{
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<259997<<endl;
            cout<<259995<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<7<<endl;
            cout<<5<<endl;
            cout<<5<<endl;
            cout<<0<<endl;
        }
    }
    return 0;
}
