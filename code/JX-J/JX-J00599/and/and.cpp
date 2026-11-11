#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int a[N],b[N];
int n,m;

long long mx = 0;

void dfs(int x,int cnt){
    if(cnt>m){
        long long t = b[1];
        for (int i = 2; i <= m; i++){
            t&=b[i];
        }
        mx = max(mx,t);
        return;
    }
    for (int i = x; i <= n; i++){

        b[cnt] = a[i];
        dfs(x+1,cnt+1);
        x+=1;
    }
}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dfs(1,1);

    cout << mx;

    return 0;
}
