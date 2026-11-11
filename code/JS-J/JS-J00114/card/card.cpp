#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
stack<int> st;
int a[N],cnt[M];
bool used[M];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        for(int j=i;j<=n;j++){
            int k=a[j];
            if(used[k]==0){
                used[k]=1;
                st.push(k);
            }
            else {
                while(st.top()!=k) st.pop();
            }
        }
        while(!st.empty()){
            int kk=st.top();
            st.pop();
            cnt[kk]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
