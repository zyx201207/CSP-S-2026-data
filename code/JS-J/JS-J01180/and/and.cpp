#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=b-1;i>=a;i--)
int n,k,ans,tmp,a[200007],cnt[37];
bool vis[200007];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    fr(i,0,n)cin>>a[i];
    rf(NUM,0,30){
        fr(i,0,n){
            if(vis[i])continue;
            cnt[NUM]+=((a[i]&(1<<NUM))>0);
        }
        //cout<<cnt[NUM]<<endl;
        if(cnt[NUM]<k)continue;
        fr(i,0,n){
            if((a[i]&(1<<NUM))>0);
            else vis[i]=1;
        }
        ans+=(1<<NUM);
    }
    cout<<ans<<endl;
    return 0;
}
