#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000000]={0},b[2000000]={0},e=0,f=1;
int main(){
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    cin>>c>>t;
    for (int j=1; j<=t; j++){
        cin>>n>>d;
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
        for (int i=n; i>=1; i--){
            if (a[i]-2>=d){
                e+=1;
            }
        }
        b[f]=e;
        f+=1;
        e=0;
    }
    for (int i=1; i<=t; i++){
            cout<<b[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
