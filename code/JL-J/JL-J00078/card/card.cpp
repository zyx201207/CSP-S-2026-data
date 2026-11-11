#include<bits/stdc++.h>
using namespace std;

const int N = 5e5  + 10;
int a[N];
int ca[N];
bool vis[N];
stack<int> k;
map<int, int> mp;

int main() {

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int m, n;
    cin >> n >> m;

    for(int i = 1;i <= n;i ++) {
        int x;
        cin >> a[i];
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1 + i - 1;j <= n;j ++) {
            mp[a[j]] ++;
            if(mp[a[j]] > 1) {
                while(k.top() != a[j] && k.size()) {
                    int s = k.top();
                    k.pop();
                    mp[s] --;
                    vis[i] = 1;
                }
                mp[k.top()] --;
                k.pop();
            }
            k.push(a[j]);
            vis[a[j]] = 0;
        }
        for(int j = 1;j <= n;j ++) {
            if(!vis[j]) {
                ca[j] ++;
            }
        }


    }



    for(int i = 1;i <= m;i ++) {
        cout << ca[i] << ' ';
    }

    return 0;
}
