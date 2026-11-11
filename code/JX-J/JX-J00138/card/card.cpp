#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=500010;

int n,m;
int a[N],lt[N],pos[N],ans[N],s[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],pos[i]=i;
    map<int,int>mp;
    for(int i=n;i>=1;i--){
        if(mp.find(a[i])==mp.end()) lt[i]=-1;
        else lt[i]=mp[a[i]];
        mp[a[i]]=i;
    }
//    for(int i=1;i<=n;i++) cout<<pos[i]<<" "<<lt[i]<<"\n";
    int res=0;
    for(int i=1;i<=n;i++){
        s[i]+=s[i-1],pos[i]+=s[i];
        if(lt[i]!=-1){
            s[i]-=pos[i],s[lt[i]]+=pos[i],pos[i]=0;
        }
 //       cout<<pos[i]<<" ";
        ans[a[i]]+=pos[i];
    }
//    cout<<"\n";
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--) solve();
}
