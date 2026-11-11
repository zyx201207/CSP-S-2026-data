#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],maxx=-1,an[200009];
void dfs(long long floor,int j){
    if(floor-1==m){
        long long ans=an[1];
        for(int i=2;i<floor;i++){
            ans=ans&an[i];
        }
        maxx=max(maxx,ans);
        return;
    }
    for(int i=j;i<=n;i++){
        an[floor]=a[i];
        dfs(floor+1,i+1);
        an[floor]=0;
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    cout<<maxx;
    return 0;
}
