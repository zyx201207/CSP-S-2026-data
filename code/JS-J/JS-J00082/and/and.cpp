#include <bits/stdc++.h>
using namespace std;
int n,m,b[200005];
long long maxn;
void dfs(int step,vector<int> a,long long sum){
    if(step>m){
        maxn=max(maxn,sum);
        return;
    }
    for(int i=0;i<n;i++){
        if(b[i]){
            continue;
        }
        if(a[i]<maxn){
            continue;
        }
        b[i]=true;
        //cout<<i<<' ';
        dfs(step+1,a,sum&a[i]);
        b[i]=false;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(1,a,(long long)pow(2,31)-1ll);
    cout<<maxn;
    return 0;
}