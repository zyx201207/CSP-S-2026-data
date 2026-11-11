#include<bits/stdc++.h>
using namespace std;
vector<int> v;
const int MAXN=5*1e5+10;
int a[MAXN];
int ans[MAXN];
int check(int m){
    for(int i=0;i<v.size();i++){
        if(v[i]==m) return i;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=check(a[j]);
            int s=v.size();
            if(x==-1) v.push_back(a[j]);
            else {for(int k=x;k<=s;k++){
                v[k]=0;
            };v.push_back(a[j]);}
        }
    for(int j=0;j<v.size();j++){
        if(v[j]!=0) ans[v[j]]++;
    }
    }
    for(int i=1;i<=m;i++){
        while(ans[i]==0)i++;
        cout<<ans[i]<<" ";
    }
    return 0;
}
