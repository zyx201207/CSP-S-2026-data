#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+7;
const int maxm=3e5+7;

int n,m;
int a[maxn];
int cnt[maxm]={0};

void solve(int x){
    stack<int> st;

    for(int i=x;i<=n;i++){
        if(st.empty()){
            st.push(a[i]);
        }else{
            stack<int> tmp;
            bool find=false;

            while(!st.empty()){
                tmp.push(st.top());
                st.pop();

                if(tmp.top()==a[i]){
                    find=true;
                    break;
                }
            }

            if(!find){
                while(!tmp.empty()){
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
            st.push(a[i]);
        }
    }

    while(!st.empty()){
        cnt[st.top()]++;
        st.pop();
    }

    return;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
        solve(i);

    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";

    return 0;
}
