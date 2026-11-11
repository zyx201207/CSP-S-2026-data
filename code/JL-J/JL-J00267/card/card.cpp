#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool in(int x, stack<int> d){
    bool flag = false;
    stack<int> t = d;
    while(1){
        if(t.top() == x){
            flag = true;
            return flag;
        }
        t.pop();
    }
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out","w",stdout);
    int n, m;
    a.resize(n + 10);
    stack<int> d;
    for(int i = 1; i < n; i++)
        cin >> a[i];
    for(int Y = 1; Y <= m; Y++){
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = i; j < n; j++){
                if(!in(a[j], d))  d.push(a[j]);
                else{
                    while(d.top() != a[j]){
                        d.pop();
                    }
                }
            }
        }
        if(in(Y, d)) ans++;
        cout << ans << " ";
    }
    return 0;
}