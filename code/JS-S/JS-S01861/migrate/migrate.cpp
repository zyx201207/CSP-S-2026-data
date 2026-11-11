#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000006];



signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){

        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>=2){

            }
        }

        int cnt=0;

            int kk=x[2]-x[1];
            int limi=d/kk;
            if(d<kk*2){
                cout<<0<<endl;
                continue;
            }
            for(int i=2;i<=limi;i++){
                if(n<i*2){
                    break;
                }
                cnt+=(n-i*2+1);

            }
            cout<<cnt<<endl;
            continue;





    }

    return 0;
}
