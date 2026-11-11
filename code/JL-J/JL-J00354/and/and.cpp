#include <bits/stdc++.h>
using namespace std;
chira N[200005]
int p,n,m,a=0,b;
int main(){
    freopen("and.in","r",std.in);
    freopen("and.out","w",std.out);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>N[i];
    }
    for(int i=1;i<=n;i++){
        b=a;
        a=N[i]||N[i-1];
        if(a>b){
            b=a;
        }
    }
    cout<<b;
    return 0;
}
