#include<bits/stdc++.h>
using namespace std;
int n,m;
multiset<int> st;

int cnt(int x){
    int ans=0;
    while(x){
        ans+=(x%2);
        x/=2;
    }
    return ans;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ans=0;
    int x=0;
    for(int i=1; i<=n; i++){
        int a;cin>>a;
        if(cnt(a)>cnt(ans)){
            ans=a;
            x=a;
        }
        st.insert(a);
    }
    auto it=st.find(x);
    st.erase(it);
    bool change=false;
    for(int i=2; i<=m; i++){
        int k=ans&(*st.begin());
        x=(*st.begin());
        for(int p:st){
            if((p&ans)>k){
                k=p&ans;
                x=p;
            }
        }
        ans=k;
        it=st.find(x);
        st.erase(it);
    }
    cout<<ans;
    return 0;
}
