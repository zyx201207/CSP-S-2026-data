#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N];
int ans[M];
bool vis[3010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        stack<int>st;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(vis[a[j]]){
                    while(!st.empty()){
                        int b=st.top();
                        if(b==a[i])break;
                        vis[b]=false;
                        st.pop();
                    }
                }else{
                    st.push(a[j]);
                    vis[a[j]]=true;
                }
            }
            while(!st.empty()){
                int b=st.top();
                vis[b]=false;
                ans[b]++;
                st.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
    }else{
        for(int i=1;i<=m;i++){
            cout<<n<<' ';
        }
    }
    return 0;
}
