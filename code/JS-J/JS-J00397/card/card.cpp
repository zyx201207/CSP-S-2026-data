#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAXN=5e5;
int n,m,ans;
int a[MAXN];
bool solve(int x){
    vector<int> v;
    for(int i=x;i<=n;i++){
        bool f=0;
        for(int i=0;i<v.size();i++){
            if(f=1) v.erase(v.begin()+i);
            else if(v[i]==a[i]) f=1;
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]==x)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<m;i++){
        ans+=solve(i);
    }
    cout<<ans<<endl;
    return 0;
}