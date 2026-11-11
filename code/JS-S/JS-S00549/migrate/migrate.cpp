#include<bits/stdc++.h>
using namespace std;
int f[10005];
int c,t;
int n,d,a[1000005];
int s;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }

    if(a[i+1]-a[i+2]==a[i]-a[i+1]&&a[i+2]-a[i+3]==a[i+1]-a[i+2]){
        f[i]=n-3;
        }
    }

    for(int i=1;i<=t;i++){
        cout<<f[i]<<endl;
    }
    return 0;
}
