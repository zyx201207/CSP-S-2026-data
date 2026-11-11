#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],ans[300002];
bool b[300002];
stack<long long>st;
set<long long>se;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        while(!st.empty()){
            st.pop();
        }
        memset(b,false,sizeof(b));
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                while(st.top()!=a[j]&&!st.empty()){
                    st.pop();
                }
            }else{
                b[a[j]]=true;
                st.push(a[j]);
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
