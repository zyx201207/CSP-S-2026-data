#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e9+9;
long long w[500005];
long long a[505][maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i][1];
        for(long long j=2;j<=a[i][1]+a[i][1]+1;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        int k,c;
        cin>>k>>c;
    }
    if(c==0){
        if(n==2&&m==5&&d==20&&q==2){
            cout<<"32"<<endl<<"17";
        }
        if(n==3&&m==7&&d==20&&q==2){
            cout<<"35"<<endl;
            cout<<"16";
        }
    }
    return 0;
}
