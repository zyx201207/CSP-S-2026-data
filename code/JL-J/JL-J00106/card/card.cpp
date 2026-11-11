#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ull unsigned long long
#define pb push_back
#define mii map<int,int>
#define pii pair<int,int>
#define si stack<int>
#define qi queue<int>
#define miao return 0;
using namespace std;

const signed int N = 5e5+5;

int n,m;
int a[N];
int ans[N];
si st;
map<int,bool> mp;

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;
    int ls = -1;
    bool flag = 1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] < ls) flag = 0;
        ls = a[i];
    }

    if(flag){
        for(int i=0;i<m;i++){
            cout << i+1 << " ";
        }
        miao
    }

    for(int t=1;t<=n;t++){
        while(!st.empty()) st.pop();
        for(int i=1;i<=m;i++) mp[i] = 0;

        for(int i=t;i<=n;i++){
            if(mp[a[i]] == 1){
                while(!st.empty()){
                    // cout << ">>>" << st.top() << " " << a[i] << " " << i << endl;
                    mp[st.top()] = 0;
                    if(st.top() == a[i]) break;
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            st.push(a[i]);
            mp[a[i]] = 1;
        }

        // cout << "Case " << t << " : ";
        while(!st.empty()){
            // cout << st.top() << ' ';
            ans[st.top()]++;
            st.pop();
        }
        // cout << endl;
    }

    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }

    miao
}