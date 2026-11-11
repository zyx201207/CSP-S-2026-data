#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5+10;
int n,m;
int a[N],cnt[N],flag[N];
stack<int> st;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        for(int j = i;j<=n;j++){
            if(flag[a[j]]){
                while(1){
                    int x = st.top();
                    if(x==a[j]) break;
                    st.pop();
                    flag[x] = 0;
                }
                continue;
            }
            st.push(a[j]);
            flag[a[j]] = 1;
        }
        while(!st.empty()){
            int x = st.top();
            st.pop();
            cnt[x]++;
        }
    }
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=m;i++){
        if(!flag[i]) cout<<cnt[i]<<" ";
        flag[i] = 1;
    }

    return 0;
}
