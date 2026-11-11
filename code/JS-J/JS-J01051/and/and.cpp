#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=-100000;
int a[200005];
int fangan1(int x,int y){
    for(int i=1;i<=x;i++){
        for(int j=i+1;j<=x;j++){
            maxn=max(maxn,(a[i]&a[j]));
        }
    }
    return maxn;
}
int fangan2(int x,int y){
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2||m==1){
        cout<<fangan1(n,m);
    }else{
        cout<<fangan2(n,m);
    }
    return 0;
}
