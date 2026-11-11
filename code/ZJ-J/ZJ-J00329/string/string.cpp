#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> c;
int n,m;
int ans;
void dfs(int idx){
    if(idx==m){
        ans=max(ans,accumulate(next(c.begin()),c.end(),c[0],bit_and<int>()));
        return;
    }
    else{
        dfs(idx+1);
        c.push_back(a[idx]);
        dfs(idx+1);
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    a.resize(n);
    for(int& i:a){
        cin>>i;
    }
    if(m==1){
        cout<<*max_element(a.begin(),a.end());
        return 0;
    }
    if(m==n){
        cout<<accumulate(next(a.begin()),a.end(),a[0],bit_and<int>());
        return 0;
    }
    dfs(0);
    cout<<ans;
	return 0;
}
