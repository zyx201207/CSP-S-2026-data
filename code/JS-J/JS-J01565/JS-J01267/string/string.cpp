#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5+8;

int n;
stack<pair<char,LL>> sta1;
stack<pair<char,LL>> sta2,li;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        LL x;
        cin >> x;
        char ch;
        cin >> ch;
        li.push({ch,x});
        sta1.push({ch,x});
    }
    while(!li.empty()){
        sta2.push(li.top());
        li.pop();
    }
    LL ans = 0;
    while(!sta1.empty()){
        char fst = sta1.top().first,lst = sta2.top().first;
        int fval = sta1.top().second,lval = sta2.top().second;
        sta1.pop(),sta2.pop();
        if(fst != lst){
            ans += min(fval,lval);
        }
        if(fval > lval){
            sta1.push({fst,fval-lval});
        }
        else if(fval < lval){
            sta2.push({lst,lval-fval});
        }
    }
    cout << ans/2;
}
