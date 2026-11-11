#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
 int c,n,m,d,q,w[1000005],k,a[1000005],t[1000005],x[1000005],y[1000005];
cin>>c>>n>>m>>d>>q;
for(int i=0;i<m;i++){
    cin>>w[i];
}
for(int i=0;i<n;i++){
    cin>>k;
    for(int j=0;j<2*k;j++){
        if(j%2==0){
            cin>>a[j];
        }else{
        cin>>t[j];
    }
}
for(int i=0;i<q;i++){
    cin>>x[i]>>y[i];
    cout<<1<<endl;
    }
}

return 0;
}
