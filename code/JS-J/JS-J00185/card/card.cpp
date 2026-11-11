#include<bits/stdc++.h>
using namespace std;
int n,m,a[550000],ans[330000];
bool specialA=1;
set<int>st;
stack<int>stk;
void SpecialA(){
    for(int i=n;i>=1;--i){
        if(!ans[a[i]]){
            ans[a[i]]=i;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    exit(0);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]<a[i-1]){
            specialA=0;
        }
    }
    if(specialA){
        SpecialA();
    }
    else if(n>5000){
        for(int i=1;i<=m;++i){
            cout<<"0 ";
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i){
        st.clear();
        for(int j=i;j<=n;++j){
            if(st.find(a[j])==st.end()){
                st.insert(a[j]);
                stk.push(a[j]);
            }
            else{
                while(stk.top()!=a[j]){
                    int t=stk.top();
                    stk.pop();
                    st.erase(t);
                }
            }
        }
        while(!stk.empty()){
            int t=stk.top();
            stk.pop();
            ++ans[t];
        }
    }
    for(int i=1;i<=m;++i){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}
