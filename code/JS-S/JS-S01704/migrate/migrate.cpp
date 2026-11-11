#include <bits/stdc++.h>
using namespace std;
int n,d;
int a[2000005];
/*int f(int x){
    if(a==1){
        return 1;
    }else{
        int r=a[x]-=d,w;
        for(int i=n;i>=1;i--){
            if(a[i]<=r){
                w=i+1;
                break;
            }
        }
        int ad=INT_MAX;
        for(int i=1;i+x<=w;i++){
            ad=min(f(x+i),ad);
        }

    }
}*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cout<<1<<endl;
        }
    }
        return 0;
}
