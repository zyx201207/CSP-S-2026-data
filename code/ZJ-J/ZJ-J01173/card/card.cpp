#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], an[300005];
bool v[300005];
stack<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(), cout.tie();
    freopen("card.in","r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++){
        for (int j = i; j <= n;j++){
            if(v[a[j]])while(s.top()!=a[j]){
                v[s.top()] = 0;
                s.pop();
            }else{
                v[a[j]] = 1;
                s.push(a[j]);
            }
        }
        while (!s.empty()){
            an[s.top()]++;
            v[s.top()] = 0;
            s.pop();
        }
    }
    for (int i = 1; i <= m;i++)
        cout << an[i] << " ";
    return 0;
}