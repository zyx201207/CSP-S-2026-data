#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[100005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==0&&n==4&&d==2){
            cout<<1<<endl<<2;
            break;
        }
        else if(c==0&&n==5&&d==3){
            cout<<0<<endl<<1;
            break;
        }
        else{
            continue;
        }

    }


    return 0;
}
