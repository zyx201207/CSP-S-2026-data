#include<bits/stdc++.h>
using namespace std;
int a[200009];
map<int,int> mp;
int pow_2(int x){
    int t = 1;
    while(t < x){
        t *= 2;
    }
    if(t == x){
        return 1;
    }
    else if(t - 1 == x){
        return 2;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] >= 0 && a[i] <= 4){
            mp[a[i]] = -1;
        }
        else{
            int flag = pow_2(a[i]);
            if(flag == 1){
                mp[a[i]] = -1;
            }
            else if(flag == 0){
                mp[a[i]] = 1;
            }
            else{
                mp[a[i]] = 2;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(mp[a[i]] < mp[a[j]]){
                swap(a[i],a[j]);
            }
            else if(mp[a[i]] == mp[a[j]]){
                if(a[i] < a[j]){
                    swap(a[i],a[j]);
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 1;i <= m;i++){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
