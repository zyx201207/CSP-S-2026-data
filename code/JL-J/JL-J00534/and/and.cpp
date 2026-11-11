#include <bits/stdc++.h>
using namespace std;
int n,m,maxx=0;
int a[300000];
int ad(int x,int y){
    int cnt=0,i=0;
    while(x!=0||y!=0){
        if(x%2==y%2){
            cnt+=pow(2,i);
        }
        x/=2;
        y/=2;
        i++;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            maxx=max(ad(a[i],a[j]),maxx);
        }
    }
    cout<<maxx;
    return 0;
}
