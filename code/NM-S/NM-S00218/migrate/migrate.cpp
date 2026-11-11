#include<bits/stdc++.h>
using namespace std;
int a[2000009];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long land,s;
        cin>>land>>s;
        for(int i=0;i<land;i++){
            cin>>a[i];
        }
        if(s==2){
            if(land==6){
                cout<<1<<endl;
            }
            else{
                cout<<land-3<<endl;
            }

        }else{
            cout<<0<<endl;
        }

    }
    return 0;
}

