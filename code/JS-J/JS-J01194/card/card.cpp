#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(5e5+10)
int n,m,a[MAXN],ans[MAXN]={0};
vector<int> pos[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
        pos[a[i]].push_back(i);
    } 
    for(int i=1;i<=n;i++){
        ans[a[i]]++;
        int idx=pos[a[i]].back();
        while (idx<n){
            ans[a[++idx]]++;
            idx=pos[a[idx]].back();
        }   
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}