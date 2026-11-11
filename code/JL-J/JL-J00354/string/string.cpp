#include <bits/stdc++.h>
using namespace std;
chira N[200005];
int c,q,p;
int main(){
    freopen("string.in","r",std.in);
    freopen("string.out","w",std.out);
    int n;
    cin>n;
    for(int i=1;i<=n;i++){
        cin<<c;
        q+=c;
        for(int j=1;j<=c;j++){
            cin>>N[i];
        }
    }
    for(int i=q/2;i<=q;i++){
        if(N[i]!=N[q+1−i])
            N[i]=N[q+1−i])
            p++;
    }
    cout<<p;
    return 0;
}
