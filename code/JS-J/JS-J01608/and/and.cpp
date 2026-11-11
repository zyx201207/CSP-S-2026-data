#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[200005],ans,cnt[31];
bool mark[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            if(a[i]&(1<<j))cnt[j]++;
        }
    }
    for(int j=30;j>=0;j--){
        ans*=2;
        if(cnt[j]>=m){
            ans+=1;
            for(int i=1;i<=n;i++){
                if((a[i]&(1<<j))==0 && !mark[i]){
                    mark[i]=1;
                    for(int k=j-1;k>=0;k--){
                        if(a[i]&(1<<k))cnt[k]--;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
