#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e+6;
vector<int> cnt(MAXN,0);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,maxi;
    vector<int> total;
    stack<int> st;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    while(n--){
        bitset<MAXN> b;
        int a; cin>>a;
        total.push_back(a);
        maxi = max(a,maxi);
        if(b[a]){
            while(st.top()!=a){
                st.pop();
            }
        }
        else{
            st.push(a);
        }
    }
    while (!st.empty()){
        cnt[st.top()]++;
        st.pop();
    }
    for (int i=1;i<total.size();i++){
        stack<int> tmp;
        for (int j=i;j<total.size();j++){
            bitset<MAXN> b;
            maxi = max(total[j],maxi);
            if(b[total[j]]){
                while(tmp.top()!=total[j]){
                    tmp.pop();
                }
            }
            else{
                tmp.push(total[j]);
            }
        }
        while (!st.empty()){
            cnt[tmp.top()]++;
            tmp.pop();
        }
    }
    for(int i=1;i<=maxi;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
