#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],cnt[300005];
bool flag[300005];
stack<int>st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(flag,false,sizeof flag);
        for(int j=i;j<=n;j++){
            if(flag[a[j]]==false)st.push(a[j]);
            else{
                while(st.top()!=a[j]){
                    flag[st.top()]=false;
                    st.pop();
                }
            }
            flag[a[j]]=true;
        }
        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
