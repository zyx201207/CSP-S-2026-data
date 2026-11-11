#include<bits/stdc++.h>
using namespace std;
const int N=5005;
vector<int> v;
int n,m;
int a[N],cnt[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        v.clear();
        for(int j=i;j<=n;j++){
            for(int k=0;k<v.size();k++){
                int pd=k;
                if(v[k]==a[j]){
                    while(v.size()!=pd) v.pop_back();
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(int j=0;j<v.size();j++){
            int k=v[j];
            cnt[k]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
