#include<bits/stdc++.h>
using namespace std;
int a[500005],v[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<int>st;
        set<int>s;
        for(int j=i;j<=n;j++){
            if(s.find(a[j])==s.end()){
                st.push(a[j]);
                s.insert(a[j]);
            }else{
                while(st.top()!=a[j]){
                    s.erase(st.top());
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            v[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<v[i]<<' ';
    return 0;
}



