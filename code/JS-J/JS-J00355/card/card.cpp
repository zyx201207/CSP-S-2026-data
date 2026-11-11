#include <bits/stdc++.h>
using namespace std;
void sim(vector<int>& cont,int i,vector<int>& a){
    unordered_map<int,int> last;
    vector<int> ret;
    vector<int> game(a.begin()+i,a.end());
    vector<bool> skip(a.size());
    for(int j=0;j<game.size();j++){
        if(last.count(game[j])==0){
            last[game[j]]=j;
            continue;
        }
        if(skip[last[game[j]]]){
            last[game[j]]=j;
            continue;
        }
        for(int k=last[game[j]];k<j;k++){
            skip[k]=true;
        }
        last[game[j]]=j;
    }
    bool skipping=false;
    for(int j=0;j<game.size();j++){
        if(!skip[j]){
            ret.push_back(game[j]);
        }
    }
    cont=std::move(ret);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans(m+1);
    for(int i=0;i<n;i++){
        vector<int> res;
        sim(res,i,a);
        for(auto x:res){
            ans[x]++;
        }
    }
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}