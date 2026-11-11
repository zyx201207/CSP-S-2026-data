#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int n,m;
int a[N];
int cnt[N];
bool mp[5005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        stack<int>st;
        memset(mp,0,sizeof(mp));
        for(int j=i;j<n;j++){
            if(mp[a[j]]){
                while(!st.empty()&&st.top()!=a[j]){
                    mp[st.top()]=0;
                    st.pop();
                }
            }
            else{
                mp[a[j]]=1;
                st.push(a[j]);
            }
        }
        //vector<int>ans;
        while(!st.empty()){
            int x=st.top();
            cnt[x]++;
            //ans.push_back(x);
            st.pop();
        }
        //reverse(ans.begin(),ans.end());
        //for(int i=0;i<(int)ans.size();i++) cout<<ans[i]<<' ';
        //cout<<"\n\n";
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
