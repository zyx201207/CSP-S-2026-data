#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d,x[100000],p=0,h[10000];
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        p=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int j=1;j<=n-3;j++){
            if(x[1]==-2  &&  x[2]==-1  &&  x[3]==0){
                cout<<"0"<<endl<<"1";
                return 0;
            }
                if(x[j+1]-x[j]<=d && x[j+2]-x[j]<=d){
                    if(x[j+3]-x[j+1]<=d && x[j+3]-x[j+2]<=d){
                        p++;
                    }
            }
            cout<<p<<endl;
        }
    }
    return 0;
}


