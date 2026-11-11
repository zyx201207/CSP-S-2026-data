#include<bits/stdc++.h>
using namespace std;
int a[500001],cnt[300001];
bool vis[300001];
stack<int>st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if (vis[a[j]])
                    while (st.top()!=a[j]){
                        vis[st.top()]=false;
                        st.pop();
                    }
                else{
                    vis[a[j]]=true;
                    st.push(a[j]);
                }
            }
            while (!st.empty()){
                cnt[st.top()]++;
                vis[st.top()]=false;
                st.pop();
            }
    }
    for (int i=1;i<=m;i++)
        printf("%d ",cnt[i]);
    return 0;
}
