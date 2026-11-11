#include<bits/stdc++.h>
using namespace std;
int n,c,ans;
char c1,a[10000000],zcd;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cd,zz=0;
    for(int i=1;i<=n;i++){
        cin>>cd>>c1;
        zcd+=cd;
        for(int j=1;j<=cd;j++){
            a[zz+j]=c1;
        }
        zz+=cd;
    }
    for(int i=1;i<=zcd;i++){
        if(a[i]!=a[zcd-i+1]) ans++;
    }
    cout<<ans/2;
    return 0;
}
