#include<bits/stdc++.h>
using namespace std;
int ans21,a[200005],n,m;
int cf(int b){
    int ans23=1;
    for(int i=0;i<b;i++){
        ans23*=2;
    }
    return ans23;
}
int awy(int a,int b){
    bool a1[35]={0},b1[35]={0};
    int as=0,bs=0,ans22=0;
    for(int i=0;a>0;i++){
        a1[i]=a%2;
        a=a/2;
        as++;
    }
    for(int i=0;b>0;i++){
        b1[i]=b%2;
        b=b/2;
        bs++;
    }
    for(int i=0;i<min(as,bs);i++){
        if(a1[i]==1&&b1[i]==1){
            ans22+=cf(i);
        }
    }
    return ans22;
}
void dfs(int step,int ans23,int l){
    if(step==0){
        ans21=max(ans21,ans23);
    }else{
        for(int i=l+1;i<n;i++){
            dfs(step-1,awy(ans23,a[i]),i);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        dfs(m-1,a[i],i);
    }
    cout<<ans21;
    return 0;
}
