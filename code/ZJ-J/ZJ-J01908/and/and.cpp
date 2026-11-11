#include <bits/stdc++.h>
using namespace std;
const int maxa=1e5*2+5;
int n,m;
int a[maxa];
int ans(int zhi,int ceng,int start){
    if(ceng==m){
        return zhi;
    }
    if((start==n)&&(ceng<m)){
        return 0;
    }
    int big=0;
    for(int i=start+1;i<=n;i++){
        big=max(big,ans(zhi&a[i],ceng+1,i));
    }
    return big;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int Max=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        Max=max(Max,ans(a[i],1,i));
    }
    cout<<Max;
    return 0;
}
