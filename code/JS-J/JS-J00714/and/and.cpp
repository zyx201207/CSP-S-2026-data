#include<bits/stdc++.h>
using namespace std;
int a[214514],can[30],pw[30];
bool is[214514];
vector<int> del[30];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<30;i++){
        pw[i]=pw[i-1]*2;
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        is[i]=1;
        for(int j=0;j<30;j++){
            can[j]+=((a[i]&pw[j])>0);
            if((a[i]&pw[j])==0){
                del[j].push_back(i);
            }
        }
    }
    int ans=0;
    for(int i=29;i>=0;i--){
        if(can[i]<m)continue;
        ans|=(1<<i);
        for(int j=0;j<del[i].size();j++){
            int cur=del[i][j];
            if(is[cur]==0) continue;
            is[cur]=0;
            for(int k=0;k<i;k++){
                can[k]-=((a[cur]&pw[k])>0);
            }
        }
    }
    cout<<ans;
}
