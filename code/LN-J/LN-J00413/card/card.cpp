#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[500005],n,m,b[300005];
string c;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){ cin>>a[i];}
    //if(a[1]!=a[2]) cout<<1<<" ";
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]) continue;
        cout<<i<<" ";

    }
    cout<<endl;
    /*for(int i=1;i<=n;i++) {
            c="";
        for(int j=i;j<=n;j++){
            for(int l=0;l<=c.size();l++){
                if(c[i]==char(a[j]+'0')) c.erase(i,c.size());
            }
            c+=char(a[j]+'0');
        }
        cout<<c<<endl;
        for(int j=0;j<=c.size();j++){
            b[int(c[j]-'0')]++;
        }
        for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }*/
    return 0;
}
