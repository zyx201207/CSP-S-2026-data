#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans(n,0),b;
    for(int i=0;i<n;i++){
        map<int,pair<int,int>> mp;
        b.clear();
        for(int j=i;j<n;j++){
            if(mp[a[j]].first==1){
                // cout<<j<<' ';
                // for(int k=0;k<m;k++){
                //     cout<<mp[a[k]].first<<' ';
                // }
                for(int k=mp[a[j]].second;k<b.size();){
                    //cout<<a[k];
                    mp[b[k]].first=0;
                    b.erase(b.begin()+k);
                }
                // cout<<'b';
                // for(int k=0;k<m;k++){
                //     cout<<mp[a[k]].first<<' ';
                // }
                // cout<<'\n'<<'\n';
            }
            b.push_back(a[j]);
            mp[a[j]]={1,j};
        }
        for(int k=1;k<=m;k++){
            cout<<mp[k].first<<' ';
        }
        cout<<'\n';
        cout<<"ans:";
        for(int k=1;k<=m;k++){
           ans[k]+=mp[k].first;
        }
        for(int k=1;k<=m;k++){
            cout<<ans[k]<<' ';
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}