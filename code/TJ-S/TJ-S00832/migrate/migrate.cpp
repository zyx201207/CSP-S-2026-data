#include<bits/stdc++.h>
using namespace std;
long long a[1111111],n,cnt=0,c=1,m,x,y,p;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>n>>m;
    for(int ls=1;ls<=m;ls++){
        c=0;
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            cin>>a[i];
        }

        for(int i=1;i<=x-y;i++){
            p=0;
            for(int j=i;j<=x;j++){
                if(a[j]-a[i]==2*y-1){
                    c++;
                }
                //if(a[j]==a[i]+y){
                //    p++;
                //}
            }
           // if(p==2){
                //c++;
           // }
        }

        cout<<c<<endl;
    }
    return 0;
}
