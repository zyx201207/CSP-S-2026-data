#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
vector<int> cnt[35];
bool hv[200005];
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    // sort(a,a+n);
    // for(int i=0;i<n;i++){
    //     for(int j=30;j>=0;j--){
    //         if((a[i]>>j)&1) cout<<1;
    //         else cout<<0;
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<n;i++){
        for(int j=30;j>=0;j--){
            if((a[i]>>j)&1) cnt[j].push_back(i);
        }
    }
    for(int i=0;i<n;i++) hv[i]=1;
    for(int i=30;i>=0;i--){
        int k=0;
        for(int j=0;j<cnt[i].size();j++) if(hv[cnt[i][j]]) k++;
        if(k>=m){
            ans+=(1ll<<i);
            int idx=0;
            for(int j=0;j<n,idx<cnt[i].size();j++){
                if(j==cnt[i][idx]) hv[j]=(hv[j]&&1),idx++;
                else hv[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}