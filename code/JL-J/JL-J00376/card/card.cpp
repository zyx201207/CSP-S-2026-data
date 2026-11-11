#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m;
    cin >> n >> m;
    queue<long long> a,c;
    stack<long long> b;
    vector<long long> cnt(m+1),ans(m+1);
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        a.push(x);
        c.push(x);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(!a.empty()) a.pop();
        }
        long long x = a.size();
        while(x != 0){
        if(cnt[a.front()] == 0){
        b.push(a.front());
        cnt[a.front()]++;
        a.push(a.front());
        a.pop();
        x--;
        }else{
            while(!b.empty() && b.top() != a.front()) {
            cnt[b.top()] = 0;
                b.pop();
            }
            a.push(a.front());
            a.pop();
            x--;
            }
        }
            while(!b.empty()){
                ans[b.top()]++;
                b.pop();
            }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
