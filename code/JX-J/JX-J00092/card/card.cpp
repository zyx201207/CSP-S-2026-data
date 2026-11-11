#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int k=1;k<=n;k++){
        vector<int>vec;
        for(int l=k;l<=n;l++){
            for(int i=0;i<vec.size();i++){
                if(vec[i]==a[l]){
                    int now=vec.size();
                    for(int j=1;j<=now-i;j++) vec.pop_back();
                    break;
                }
            }
            vec.push_back(a[l]);
        }
        for(auto x:vec){
            cnt[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
}
