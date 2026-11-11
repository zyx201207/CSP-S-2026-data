#include<bits/stdc++.h>
using namespace std;
long long n , m , k = 0 , now , maxn = 0 , ha , l = 0;
string a[10000005];
int b[10000005] = {};
stack<int> x;
int and(int a){
    string d;
    while(a != 0){
        x.push(a % 2);
        a /= 2;
    }
    for(int i = 1;i <= x.size();i++){
        d[i] = x.top();
        x.pop();
    }
    return d;
}
void abc(int s){
    now = 0;
    k = 0;
    if(s > n){
        for(int j = 1;j <= n;j++){
            if(b[j] == 1){
                k++;
                now ^= a[j];
            }
        }
        if(k == m){
            if(now > maxn){
                maxn = now;
            }
        }
        return;
    }
    for(int i = 0;i <= 1;i++){
        b[s] = i;
        abc(s+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>> n>> m;
    for(int i = 1;i <= n;i++){
        cin>> a[i];
    }
    abc(1);
    cout<< maxn;
    return 0;
}
