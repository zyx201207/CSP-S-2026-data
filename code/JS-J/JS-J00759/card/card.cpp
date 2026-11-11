#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=500005;
ll n,m;
ll a[MAXN];
bool used[MAXN];
ll cnt[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int> st;
    for(int i=1;i<=n;i++){
        memset(used,false,sizeof(used));
        for(int j=i;j<=n;j++){
            if(used[a[j]]){
                while(!st.empty()){
                    int x=st.top();
                    if(x==a[j]){
                        break;
                    }
                    st.pop();
                    used[x]=false;
                }
            }else{
                st.push(a[j]);
                used[a[j]]=true;
            }
        }
        while(!st.empty()){
            int x=st.top();
            st.pop();
            cnt[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}