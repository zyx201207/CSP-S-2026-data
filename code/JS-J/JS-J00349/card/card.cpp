#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>ans(m+1,-1);
    vector<bool>d(m+1,false);
    stack<int>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans[a[i]]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(!d[a[j]]){
                st.push(a[j]);
                d[a[j]]=true;
            }else while(st.top()!=a[j]){
                d[st.top()]=false;
                st.pop();
            }
        }
        while(!st.empty()){
            d[st.top()]=false;
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=0;i<=m;i++){
        if(ans[i]>-1) cout<<ans[i]<<" ";
    }
    return 0;
}
