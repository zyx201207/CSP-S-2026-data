#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2*1e6;
LL a[N];
LL c,t,n,d;
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>c>>t;
    for(LL i=1;i<=t;i++){
        cin>>n>>d;
        for(LL j=1;j<=n;j++){
            scanf("%d",&a[i]);
        }
    }
    if(d>=(a[n]-a[1])){
        cout<<"0";
    }
    if((a[2]-a[1])+(a[1]+a[n])==a[n]){
        if(d=(a[3]-a[1])){
            cout<<n-3;
        }
    }
    if(d<(a[n]-a[1])){
        if(n>=4){
            cout<<n-3;
        }
    }



















    return 0;
}
