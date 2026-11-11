#include<bits/stdc++.h>
using namespace std;
vector<int> q;
int a[300005],ans[300005],b[300005];
bool check(int x){
    for(int i:q){
        if(i==a[x]){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        q.clear();
        q.push_back(a[i]);
        for(int j=i+1;j<=n;j++){
            if(check(j)){
                q.push_back(a[j]);
            }else{
                q.empty();
                q.push_back(a[j]);
            }
        }
        for(int k=1;k<=m;k++){
            for(int t:q){
                if(k==t){
                    ans[k]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
