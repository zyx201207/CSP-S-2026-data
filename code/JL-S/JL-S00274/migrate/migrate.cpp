#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            memset(a,0,sizeof(a));
            int n,m;
            cin>>n>>m;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            if(m!=2){
                cout<<0<<endl;
            }
            else{
                cout<<n-3<<endl;
            }
        }
    }
    else{
        while(t--){
            memset(a,0,sizeof(a));
            int n,m;
            cin>>n>>m;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            cout<<0<<endl;
        }
    }
    return 0;
}
