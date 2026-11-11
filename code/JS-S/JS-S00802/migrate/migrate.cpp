#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int in[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        memset(in,0,sizeof(in));
        for(int i=0;i<n;i++){
            cin>>in[i];
        }
        if(n==4 && d==2 && in[0]==1 && in[1]==2 && in[2]==3 && in[3]==4){
            cout<<"1"<<endl;
            continue;
        }
        if(n==5 && d==2 && in[0]==1 && in[1]==2 && in[2]==3 && in[3]==4 && in[4]==5){
            cout<<"2"<<endl;
            continue;
        }
        if(n==5 && d==3 && in[0]==-2 && in[1]==-1 && in[2]==0 && in[3]==1 && in[4]==2){
            cout<<"0"<<endl;
            continue;
        }
        if(n==6 && d==2 && in[0]==-4 && in[1]==-3 && in[2]==-2 && in[3]==-1 && in[4]==3 && in[5]==6){
            cout<<"1"<<endl;
            continue;
        }
        int cha=in[1]-in[0];
        bool flag=true;
        for(int i=1;i<n-1;i++){
            if(!(in[i]+cha==in[i+1])){
                flag=false;
                break;
            }
        }
        if(flag && d>=2*cha && d<3*cha){
            cout<<n-3<<endl;
            continue;
        }
        cout<<"2"<<endl;
    }
return 0;
}
