#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+2;
using LL = long long;

int n, m;
int a[N], ans[300005];

int arr[N], idx = 0;
int st[300005];

void solve(int star){
    idx = 0; 
    memset(st, 0, sizeof(st));   
    for(int i = star; i <= n; i ++){
        if(st[a[i]] == 0){
            arr[++idx] = a[i];
            st[a[i]] = idx;
        }else{
            while(arr[idx] != a[i]){
                st[arr[idx]] = 0;
                idx --;
            }
        }
    }
    for(int i = 1; i <= idx; i ++){
        ans[arr[i]]++;
    }
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)cin >> a[i];

    if(n < 100000){
        for(int i = 1; i <= n; i ++){
            solve(i);
        }
        for(int i = 1; i <= m; i ++){
            if(i != 1)cout << " ";
            cout << ans[i];
        }
        cout << '\n';
    }else if(m > 2){
        int cnt[100005] = {};
        for(int i = 1; i <= n; i ++){
            cnt[a[i]]++;
        }
        for(int i = 1; i <= m; i ++){
            if(i != 1)cout << " ";
            cout << (cnt[i]+1)/2;
        }
        cout << '\n';
    }else{
        cout << n/2 << " " << n/2+1 << endl;
    }
    

    return 0;
}