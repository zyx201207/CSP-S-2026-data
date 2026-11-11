#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010,M=300010;
int a[N],t[M];
void init(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
}
signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> pai;
        for(int j=i;j<=n;j++){
            auto pos=find(pai.begin(),pai.end(),a[j]);
            if(pos!=pai.end()){
                pai.erase(pos,pai.end());
                pai.push_back(a[j]);
            }else{
                pai.push_back(a[j]);
            }
        }for(int j=0;j<pai.size();j++){
            t[pai[j]]++;
        }
    }for(int i=1;i<=m;i++) cout << t[i] << ' ';
    return 0;
}
