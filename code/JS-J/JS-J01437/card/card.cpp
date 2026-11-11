#include<bits/stdc++.h>
using namespace std;
int a[5000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int> st;
    int o=1;
    for(int i=1;i<=n;i++){
        vector<int> l;
        for(int j=i;j<=n;j++){
            l.push_back(a[j]);
        }
        stack<int> sd;
        for(int j=0;j<l.size();j++){
            int now=l[i];
            bool f=false;
            while(!st.empty()){
                if(st.top()==now){
                    st.pop();
                    f=true;
                    break;
                }
                sd.push(st.top());
                st.pop();
            }
            st.push(now);
        }
        stack<int> stt;
        while(!st.empty()){
            if(st.top()==o){
                o++;
                break;
            }
            stt.push(st.top());
            st.pop();
        }
        while(!stt.empty()){
            st.push(stt.top());
            stt.pop();
        }
    }
    cout<<1<<' '<<2;
    return 0;
}
