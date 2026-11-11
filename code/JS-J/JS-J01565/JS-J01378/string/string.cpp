#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int xi=1,xj=0,yi=n,yj=a[n]+1,xs,ys,s;
    long long sum=0;
    while(1){
        xs=a[xi]-xj;
        ys=yj-1;
        s=min(xs,ys);
        if(c[xi]!=c[yi]) sum+=s;
        xj+=s;
        yj-=s;
        if(xj==a[xi]) xi++,xj=0;
        if(yj==1) yi--,yj=a[yi]+1;
        if(xi>=yi) break;
    }
    cout<<sum;
    return 0;
}
