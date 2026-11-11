#include<iostream>
using namespace std;
int n,m,ans;
int arr[200005];
void dg(int pos,int dep,int num){
    if (pos>n || dep>m || (n-pos)<(m-dep)) return ;
    if (dep==m){
        ans=max(ans,num&arr[pos-1]);
        return ;
    }
    if (dep==1) {
        for (int i=1;i<=n-pos;i++) dg(pos+i,dep+1,num);
    }
    else {
        for (int i=1;i<=n-pos;i++) dg(pos+i,dep+1,num&arr[pos-1]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>arr[i];
    for (int i=1;i<=n;i++) dg(i,1,arr[i-1]);
    cout<<ans;
    return 0;
}
