#include<bits/stdc++.h>
using namespace std;
int a[100010];
int cnt[100010];

int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=n;i++){
        stack<int> st;
        int p[100010]={0};
        int lin=0;
        for(int j=i;j<=n;j++){
            if(p[a[j]]!=0){
                for(int k=p[a[j]];k<lin;k++){
                    st.pop();
                    lin--;
                }
            }
            p[a[j]]=j;
            st.push(a[j]);
            lin++;
        }
        bool f[100010]={0};
        for(int j=0;j<=st.size();j++){
            if(f[st.top()]==0){
                cnt[st.top()]++;
                f[st.top()]=1;
                st.pop();
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
