#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nums[200005];
ll n,m,maxans=0;
void dfs(ll step,ll src,ll recent_ans){//step-the th of selected; src-recent th
    //cout<<"DFS:"<<step<<' '<<src<<' '<<recent_ans<<endl;
    if(step==m){
        //cout<<"End DFS\n";
        if(recent_ans>maxans){
            //cout<<"change max to:"<<maxans<<endl;
            maxans=recent_ans;
        }return;
    }for(ll i=src+1;i<=n;i++){
        //cout<<"start DFS with recent_ans:"<<recent_ans<<"AND"<<nums[i]<<endl;
        dfs(step+1,i,recent_ans&nums[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>nums[i];
    }
    for(ll i=1;i<=n;i++)dfs(1,i,nums[i]);
    cout<<maxans;
    return 0;
}
