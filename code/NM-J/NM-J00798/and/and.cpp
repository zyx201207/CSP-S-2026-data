#include<bits/stdc++.h>
using namespace std;
int miao[500010], n, m;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("and3.in", "r", stdin);
    freopen("and3.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> miao[i];
    }
    sort(miao + 1, miao + n + 1, cmp);
    int a = 1;
    for(int i = 2; i <= n; i ++){
        if(miao[i] != miao[i - 1]) a++;
        if(a == m){
            cout << miao[i];
            break;
        }
    }
    return 0;
}
