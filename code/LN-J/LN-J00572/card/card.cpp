#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
void init(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
}
int n,m;
int a[N],cnt[N];
int flag[N];
signed main(){
    init();
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        vector<int> v;
        for(int j=i;j<=n;j++){
            while(flag[a[j]]){
                flag[v[v.size()-1]]=0;
                v.pop_back();
            }
            v.push_back(a[j]);
            flag[a[j]]=1;
        }
        for(auto x:v) cnt[x]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
