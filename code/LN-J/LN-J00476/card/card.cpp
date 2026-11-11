#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll type[300005];
queue<ll> hand_temp;
stack<ll> table;
vector<bool> out(500005, false);
vector<ll> hand;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        hand.push_back(t);
        hand_temp.push(t);
    }
    for(int i = 0; i < n; i++) {
        cout << hand[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j--) {
            if(out[hand_temp.front()]) {
                while(table.top() != hand_temp.front()) {
                    table.pop();
                }
                table.pop();
            }
            out[hand_temp.front()] = true;
            table.push(hand_temp.front());
            hand_temp.pop();
            cout << hand_temp.front() << ' ';
        }
        cout << endl;
        for(int j = 0; j < table.size(); j++) {
            type[table.top()]++;
            cout << table.top() << ' ';
            table.pop();
        }
        cout << endl;
        for(int j = i + 1; j < n; j++) {
            hand_temp.push(hand[j]);
        }
    }
    for(int i = 0; i < m; i++) {
        cout << type[i] << ' ';
    }
    cout << endl;

    return 0;
}
