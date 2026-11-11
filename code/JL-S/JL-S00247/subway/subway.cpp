#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a[500005],t[500005],x,y,sum=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }
        sum=0;
        for(int j=x;j<=y;j++){
            sum=sum+w[j]+t[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
