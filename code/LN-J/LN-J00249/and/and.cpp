#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10;
int dp[N][N];

int a_(bool x,bool y){

    if(x==1 && y==1){
        return 1;
    }else{
        return 0;
    }
}
int ad(int x,int y){
    int ax[30],ay[30];
    int lenx=1,leny=1;
    while(x!=0){
        ax[lenx]=x%2;
        x/=2;
        lenx++;
    }
    while(y!=0){
        ay[leny]=y%2;
        y/=2;
        leny++;
    }
    lenx=max(lenx,leny);
    int ans=0,m=1;
    for(int i=1;i<=lenx;i++){
        ans+=m*(a_(ax[i],ay[i]));
        m*=2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a[N];
    int n,m;
    cin>>n>>m;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1){
        cout<<mx;
    }else if(m==2){
        mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mx=max(mx,ad(a[i],a[j]));
            }
        }
        cout<<mx;
    }else if(m==n){
        mx=a[1];
        for(int i=2;i<=n;i++){
            mx=(ad(mx,a[i]));
        }
        cout<<mx;
    }
    return 0;
}
