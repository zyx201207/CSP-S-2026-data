#include <bits/stdc++.h>
using namespace std;
int t,c,x[33550336],ans;
int pan(int f,int l){
    if(l-f<=3){
        return 0;
    }
    int w=0;
    for(int q=1;q<=l;q++){
        if((l-f)%d==0){
            w++;
        }
    }
    return w;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int io=1;io<=t;io++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(pan(i,j)==2){
                    ans++;
                }

            }
        }
    }
    cout<<ans;
    return 0;
}


