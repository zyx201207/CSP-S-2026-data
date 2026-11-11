#include<bits/stdc++.h>
using namespace std;

int n , m;
int a[500005];
int t[300005];
int u[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = n;i >= 1;i--){
        if(u[a[i]] == 0) u[a[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        int l = i;
        while(u[a[l]] >= l and l <= n){
            t[a[l]]++;
            l = u[a[l]]+1;
        }
        if(l < n) t[a[l]]++;
    }
    for(int i = 1;i <= m;i++){
        cout << t[i] << ' ';
    }
    return 0;
}
