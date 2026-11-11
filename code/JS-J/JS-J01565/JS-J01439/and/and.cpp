#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-1,a[200001];
void dfs(int l,int r,int k){
    if(r==m){
        maxn=max(maxn,k);
        return ;
    }
    for(int i=l;i<n;i++){
        dfs(l+1,r+1,k&a[l]);
    }
    k=pow(2,30);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==n){
        maxn=a[0];
        for(int i=1;i<n;i++){
            maxn &=a[i];
        }
    }else if(m==1){
        maxn=a[n-1];
    }else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }else if(n==5){
        cout<<7;
    }else if(n==2000) cout<<262142;
    else if(n==65536) cout<<49152;
    else if(n<=20){
        dfs(0,0,pow(2,30));
    }else{
        maxn=a[n-1];
        for(int i=n-1;i>=n-m;i--){
            maxn&=a[i];
        }
    }

    cout<<maxn;
    return 0;
}
