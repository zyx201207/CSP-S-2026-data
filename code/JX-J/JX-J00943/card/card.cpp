#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[500005];
int ans[300005];
unordered_map<int,bool> ump;
void solve(int x){
    stack<int> st;
    ump.clear();
    for(int i=n-1-x+1;i<n;i++){
        if(!ump[r[i]]){
            st.push(r[i]);
            ump[r[i]]=1;
        }else{
            while(!st.empty()&&st.top()!=r[i]){
                ump[st.top()]=0;
                st.pop();
            }
        }
    }
    while(!st.empty()){
        ans[st.top()]++;
        st.pop();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool A=1;
    for(int i=0;i<n;i++){
        cin>>r[i];
        if(i&&r[i-1]>r[i]) A=0;
    }
    if(A){
        for(int i=n-1,k=1;i>=0;i--,k++){
            if(ans[r[i]]==0){
                ans[r[i]]=n-k+1;
            }
        }
    }else for(int i=1;i<=n;i++) solve(i);
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}