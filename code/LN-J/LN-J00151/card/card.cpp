#include<bits/stdc++.h>
#define int long long
const int N=3e5+5;
using namespace std;
int a[N],tong[N],ans[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        stack<int>st;
        for(int i=1;i<=m;i++){
            tong[i]=0;
        }
        for(int i=l;i<=n;i++){
            if(tong[a[i]]==1){
                while(true){
                    int kk=st.top();
                    if(kk==a[i]){
                        break;
                    }
                    st.pop();
                    tong[kk]-=1;
                }
            }else{
                st.push(a[i]);
                tong[a[i]]=1;
            }
        }
        while(!st.empty()){
            int num=st.top();
            st.pop();
            ans[num]+=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
