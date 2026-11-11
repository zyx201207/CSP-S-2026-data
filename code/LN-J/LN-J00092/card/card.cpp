#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
bool vis[M];
int sum[M];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bool typeA=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i-1]>a[i])typeA=false;
    }
    stack<int>st;
    if(typeA){
        for(int i=1;i<=m;i++){
            cout<<n;
            if(i!=m)cout<<' ';
        }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(vis[a[j]]==false){
                    vis[a[j]]=true;
                    st.push(a[j]);
                }else{
                    while(st.top()!=a[j])st.pop();
                }
            }
            for(int i=0;i<st.size();i++){
                sum[st.top()]++;
                st.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<sum[i];
            if(i!=m)cout<<' ';
        }
    }
    return 0;
}
