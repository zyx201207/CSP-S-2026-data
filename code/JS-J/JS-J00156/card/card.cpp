#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
bool ok[N];
long long cnt[N];
stack<int>st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            if(!ok[a[i]]){
                st.push(a[i]);
                ok[a[i]]=true;
                for(int i=1;i<=m;i++){
                    if(st.size()==i){
                        cnt[i]++;
                    }
                }
            }
            else{
                while(st.size()>0){
                    if(st.top()!=a[i]){
                        st.pop();
                    }
                }
                for(int i=1;i<=m;i++){
                    if(st.size()==i){
                        cnt[i]++;
                    }
                }
                ok[a[i]]=false;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
