#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans=0;
void d(int x,int y,int z){
    if(y==m){
        ans=max(ans,z);
        return;
    }
    else{
        for(int i=x;i<=n;i++){
            int k=z&a[i];
            d(i+1,y+1,k);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)d(i+1,1,a[i]);
    cout<<ans;
    return 0;
}
