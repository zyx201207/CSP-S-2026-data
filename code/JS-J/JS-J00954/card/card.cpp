#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>

using namespace std;

int n, m;
vector<int> a;

int main() {

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    a.resize(n + 2);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i) {
        stack<int>st;
        vector<int>bck;
        set<int>s;
        for(int j = n; j >= i; --j) {
            st.push(a[i]);
            s.insert(a[i]);
        }
        vector<int>tmp;
        for(int j = i; st.empty() && bck.empty(); ++j) {
            if(st.empty()) {
                for(int m = bck.size() - 1; m >= 0; --i) {
                    st.push(bck[m]);
                }
                bck.assign(1, 0);
            }
            if(s.count(st.top()) == 1) {
                int tmpn = st.top();
                st.pop();
                s.erase(tmpn);
                bck.push_back(tmpn);
            }
            else {
                bool flag = false;
                while(!st.empty()) {
                    if(flag) {
                        st.pop();
                        continue;
                    }
                    int tmpn = st.top();
                    st.pop();
                    if(tmpn == a[j]) {
                        flag = true;
                    }
                    tmp.push_back(tmpn);
                }
                for(int m = tmp.size() - 1; m >= 0; --i) {
                    st.push(tmp[m]);
                }
            }
        }
        int cnt = 0;
        for(int c:tmp) {
            if(c == i) {
                ++cnt;
            }
        }
        cout << cnt << ' ';
    }
    return 0;
}