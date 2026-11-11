#include<bits/stdc++.h>
using namespace std;
int c,t;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
        int ans=0;
        int cc=0;
        int n=0,d=0;
        int a[2000010]{0};
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];

        }
        cc=a[2]-a[1];
        if(cc<0){
            cc-=cc;
            cc-=cc;
        }
        //cout<<"cc="<<cc;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(j-i==d/cc+1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    }
    return 0;
}
