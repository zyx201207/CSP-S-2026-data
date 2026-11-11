#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
stack<int> st;
bool t[N];
int awa[N];
int main() {
    ifstream cin("card.in");
    ofstream cout("card.out");
    cin >> n >> m;
    int p;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) t[j] = false;
        for (int j = i ; j <= n ; j++) {
            if (t[a[j]]) while (st.top() != a[j]) {
                t[st.top()] = false;
                st.pop();
            }
            else {
                t[a[j]] = true;
                st.push(a[j]);
            }
        }
        while (!st.empty()) {
            awa[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1 ; i <= m ; i++)
        cout << awa[i] << " ";
    return 0;
}
