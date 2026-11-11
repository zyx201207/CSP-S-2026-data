#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000010];

int fac(int i/*fr;i+3.la*/){
    if((a[i]+d<a[i+3])&&(a[i]+d>=a[i+2])&&(a[i]+d>=a[i+1])&&(a[i+1]+d>=a[i+3])&&(a[i+2]+d>=a[i+3])){
        return 1;
    }
    //boos+=a[i]+d<a[i+3];
    //boos+= a[i]+d>=a[i+2];
    //boos+= a[i]+d>=a[i+1];
    //boos+= a[i+1]+d>=a[i+3];
    //boos+= a[i+2]+d>=a[i+3];
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int lll=1;lll<=t;lll++){
        int ans=0;
        cin>>n>>d;
        for(int i=0;i<=2000009;i++){
            a[i]=0;
        }// first draw

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        for(int i=1;i<=n-3;i++){
            for(int j=4;j<=n;j++){
                int face=0;
                    for(int k=i;k<=j-3;k++){
                            //cout<<i<<' '<<j<<':';
                      face+=fac(k);
                    }
                if(face==1){
                        bool facd=0;
                        for(int k=i;k<=j-1;k++){
                            if(a[k]+d>=a[k+1]){
                               continue;
                            }
                            else{
                                facd=1;
                            }
                        }
                        //cout<<"+1"<<endl;
                        if(facd==0){
                           ans++;
                        }
                }
            }
        }
        cout<<ans<<endl;
    }



return 0;
}
