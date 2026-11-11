#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[5010],cnt[5010],b[5010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        stack<int>st;
        for(int i=1;i<=n;i++){
            while(!st.empty()) st.pop();
            for(int j=1;j<=n;j++){
                cnt[j]=0;
                b[j]=0;
            }
            int l=0;
            for(int j=i;j<=n;j++){
                if(cnt[a[j]]==0){
                    b[++l]=a[j];
                    cnt[a[j]]=l;
                    st.push(a[j]);
                }
                else{
                    l=cnt[a[j]];
                    while(st.top()!=a[j]){
                        int x=st.top();
                        st.pop();
                        cnt[x]=0;
                    }
                }
            }
            for(int j=1;j<=l;j++){
                ans[b[j]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
