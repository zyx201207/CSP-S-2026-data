#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
stack<int> st;
ll ans=0;
int n,m;
ll Max=0;
ll deal(){
    string s;
    ll ans=a[st.top()];
    s+=(st.top()+'0');
    st.pop();
    while(!st.empty()){
        s+=(st.top()+'0');
        ans&=a[st.top()];
        st.pop();

    }
    for(int i=s.size()-1;i>=0;i--){
        st.push(s[i]-'0');
    }
    return ans;
}
void dfs(int x){
    if(st.size()==m){
        Max=max(Max,deal());
        return ;
    }
    if(x==n) return ;
    for(int i=x+1;i<=n;i++){
        st.push(i);
        dfs(i);
        st.pop();
    }
}
int main(){
    freopen("ans.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        ll Max=0;
        for(int i=1;i<=n;i++){
            Max=max(Max,a[i]);
            cout<<Max;
            return 0;
        }
    }
    if(m==2){
        ll Max=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                Max=max(Max,(a[i]&a[j]));
            }
        }
        cout<<Max;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(n<=20){
        dfs(0);
        cout<<Max;
        return 0;
    }
    else{
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
        return 0;
    }
    return 0;
}
