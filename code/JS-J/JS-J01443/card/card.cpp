#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+7,M=3e5+7;
int a[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        vector<int>cd;
        map<int,int>mp;
        for(int j=i;j<=n;j++){
            if(mp.find(a[j])!=mp.end()&&mp[a[j]]!=-1){
                int k=cd.size()-1;
                while(cd[k]!=a[j]){
                    mp[cd[k]]=-1;
                    cd.pop_back();
                    k--;
                }
                cd.pop_back();
                mp[a[j]]=cd.size();
            }else{
                if(mp.find(a[j])!=mp.end()) mp[a[j]]=cd.size();
                mp.insert({a[j],cd.size()});
            }
            cd.push_back(a[j]);
        }
        for(auto it:cd){
            ans[it]++;
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << ' ';
    return 0;
}
