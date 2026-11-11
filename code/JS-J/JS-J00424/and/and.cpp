#include<bits/stdc++.h>
using namespace std;
int a[200005];
int _and(int x,int y){
    int ans[32];
    int p=1;
    memset(ans,0,sizeof(ans));
    while(x||y){
        if(x%2==1&&y%2==1){
            ans[p]=1;
        }
        p++;
        x/=2;
        y/=2;
    }
    int v=1;
    int sum=0;
    for(int k=1;k<=30;k++){
        if(ans[k]==1){
            sum+=v;
        }
        v*=2;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxx=0;
    for(int i=1;i<=n-m+1;i++){
        int num=a[i];
        for(int j=i+1;j<=i+m-1;j++){
            num=_and(num,a[j]);
        }
        maxx=max(maxx,num);
    }
    cout<<maxx;
}
