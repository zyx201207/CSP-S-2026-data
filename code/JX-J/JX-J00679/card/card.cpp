#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m,a[maxn],cnt[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        map<int,bool> m;
        stack<int> st;
        for(int j=i;j<=n;j++){
            if(m[a[j]]==1){
                m[a[j]]=0;
                while(st.top()!=a[j])st.pop();
            }else{
                m[a[j]]=1;
                st.push(a[j]);
            }
        }
        while(st.size()){cnt[st.top()]++;/*cout<<st.top()<<' ';*/st.pop();}
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
