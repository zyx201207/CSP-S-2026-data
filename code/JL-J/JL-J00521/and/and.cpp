#include <bits/stdc++.h>
using namespace std;
int a[200010];
int n,m;
int answer = -1;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    if (m == 1){
        answer = a[1];
    }else if (m == n){
        int cache = a[1];
        for (int i = 1;i <= n;i++){
            cache = cache & a[i];
        }
        answer = cache;
    }else {
        answer = a[m];
    }
    cout << answer;
    return 0;
}
