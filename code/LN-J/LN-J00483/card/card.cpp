#include<bits/stdc++.h>
using namespace std;
const int maxN=3*100001;
int a[maxN];
bool tong[maxN];
int cnt[maxN];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(tong[a[j]]==false){
                st.push(a[j]);
                tong[a[j]]=true;
            }
            else{
                while(st.top()!=tong[a[j]]){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
        for(int j=i;j<=n;j++){
            tong[a[j]]=false;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
