#include<bits/stdc++.h>
using namespace std;
int a[500009],ans[100009];
vector<int> v;
map<int,int> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            mp[j] = 0;
        }
        v.clear();
        for(int j = i;j <= n;j++){
            if(mp[a[j]] == 0){
                v.push_back(a[j]);
                mp[a[j]] = 1;
            }
            else{
                bool flag = 0;
                for(int k = 0;k < (int)v.size();k++){
                    if(v[k] == a[j]){
                        flag = 1;
                    }
                    if(flag == 1){
                        mp[v[k]] = 0;
                        v[k] = 0;
                    }
                }
                v.push_back(a[j]);
                mp[a[j]] = 1;
            }
        }
        for(int j = 1;j <= m;j++){
            if(mp[j] == 1){
                ans[j]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
