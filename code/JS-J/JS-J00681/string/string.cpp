#include<bits/stdc++.h>
#define int long long

int N;
struct node{
    int a; char b;
}arr[200005];

void solve(){
    std::cin >> N;
    for(int i=1;i<=N;i++)std::cin >> arr[i].a >> arr[i].b;
    int l = 1,r = N;
    int ans = 0;
    while(l < r){
        //std::cout << l << ' ' << r << '\n';
        if(arr[l].b == arr[r].b){
            int tmp = std::min(arr[l].a,arr[r].a);
            arr[l].a -= tmp; arr[r].a -= tmp;
            if(arr[l].a == 0)l++;
            if(arr[r].a == 0)r--;
        }else{
            int tmp = std::min(arr[l].a,arr[r].a);
            ans += tmp;
            arr[l].a -= tmp; arr[r].a -= tmp;
            if(arr[l].a == 0)l++;
            if(arr[r].a == 0)r--;
        }
    }
    std::cout << ans << '\n';
}

signed main(){
    freopen("string.in","r",stdin); freopen("string.out","w",stdout);
    std::ios::sync_with_stdio(0);std::cin.tie(0); std::cout.tie(0);
    solve();
    return 0;
}
//so ez T12?
