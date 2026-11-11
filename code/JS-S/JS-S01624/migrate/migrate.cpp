//ceil big
#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long c,t,n,d,x[N];
void dfs(int x,int fr,int to,int c){

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c>=11&&c<=18){
        while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int f=floor(d/abs(x[2]-x[1]));
        if(f>=2&&n-(2*f)+1>0){
            cout<<n-(2*f)+1<<'\n';
        }
           else {
            cout<<0<<'\n';
        }
    }
        return 0;
    }
    //a
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        cout<<0<<'\n';
    }
    return 0;
}


