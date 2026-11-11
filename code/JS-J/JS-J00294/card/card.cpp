#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
map<int,bool>mp;
stack<int>st;
int cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        int sa=i;
        int ed=n;
        for(int j = sa;j<=ed;j++){
            if(mp[a[j]]==0){
                st.push(a[j]);
                mp[a[j]]=1;
            }
            else{
                while(!st.empty()&&st.top()!=a[j]){
                    mp[st.top()]=0;
                    st.pop();
                }
            }
        }
        while(st.size()!=0){
            cnt[st.top()]++;
            //cout<<st.top()<<" ";
            st.pop();
        }
        for(int q = 1;q<=m;q++)mp[q]=0;
        while(!st.empty())st.pop();
        //cout<<endl;
    }
    for(int i = 1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
