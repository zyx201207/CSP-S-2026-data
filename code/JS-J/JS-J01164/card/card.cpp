#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int n,M;
int a[MAXN];
long long cnt[MAXM];
stack<int>st;
bool vis[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>M;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        while(!st.empty()){
            st.pop();
        }
        memset(vis,0,sizeof(vis));

        for(int j=i;j<=n;j++){
            int m=a[j];
            if(vis[m]){
                while(!st.empty()&&st.top()!=m){
                    vis[st.top()]=false;
                    st.pop();
                }

            }else if(!vis[m]){
                vis[m]=true;
                st.push(m);
            }
        }

        for(int i=1;i<=M;i++){
            if(vis[i]){
                cnt[i]++;
            }
        }

    }
    for(int i=1;i<=M;i++){
        cout<<cnt[i]<<" ";
    }
}
