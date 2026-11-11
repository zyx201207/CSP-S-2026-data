#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
/*int yh(int x,int y){
    int xx[33];
    int yy[33];
    int zz[33];
    int re=0;
    int t1=1,t2=1;
    while(x!=1){
        xx[t1]=x%2;
        x/=2;
        t1++;
    }
    while(y!=1){
        yy[t2]=y%2;
        y/=2;
        t2++;
    }
    for(int i=1;i<=max(t1,t2);i++){
        if(xx[i]==yy[i])zz[i]=1;
        else zz[i]=0;
    }
    for(int i=1;i<=max(t1,t2);i++){
        re+=zz[i]*pow(2,i-1);
    }
    return re;
}*/
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    cout<<a[n/2+1];
    return 0;
}
