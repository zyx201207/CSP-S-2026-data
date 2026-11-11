#include<bits/stdc++.h>
using namespace std;
long long a[500050],b[300050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        map<long long,long long>mp;
        stack<long long>st;
       for(int j=i;j<=n;j++){
            if(mp[a[j]]==0){
                mp[a[j]]=1;
            }
            else{
                while(st.top()!=a[j]){
                   mp[st.top()]=0;
                   st.pop();
                }
                mp[a[j]]=0;
                st.pop();
            }
            st.push(a[j]);
            mp[a[j]]=1;
        }
        while(st.size()){
            b[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    return 0;
}
