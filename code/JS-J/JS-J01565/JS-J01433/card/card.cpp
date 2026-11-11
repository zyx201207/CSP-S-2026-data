#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n];
    int ans[m]={0};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        vector<int> dp;
        map<int,bool> mp;
        for(int j=i;j<n;j++){
            if(mp[a[j]]==0){
                mp[a[j]]=1;
                dp.push_back(a[j]);
            }else{
                for(int k=0;k<dp.size();k++){
                    if(dp[k]==a[j]){
                        dp.erase(dp.begin()+k,dp.end());
                        break;
                    }
                }
                dp.push_back(a[j]);
            }
        }
        for(int j=0;j<dp.size();j++){
            ans[dp[j]-1]++;
        }
    }
    for(int i=0;i<m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}