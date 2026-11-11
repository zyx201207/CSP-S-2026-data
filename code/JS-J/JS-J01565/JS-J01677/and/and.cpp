#include<bits/stdc++.h>
using namespace std;
int n,t,maxn=INT_MIN,m;
int a[200005];
int h;
void zh(int x,int y,int z){
    int k=z;
    if(x>m) return ;
    for(int i=y+1;i<=n;i++){
        k=z&a[i];
        if(k>maxn && x==m) maxn=k;
        zh(x+1,i,k);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        h=a[i];
        zh(1,i,h);
    }
    cout<<maxn;
    return 0;
}
