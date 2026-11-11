#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n,ans = 0;
struct nod{
    int num;
    char ch;
}a[N];

void work(int &l,int &r){
    if(a[l].num > a[r].num){
        a[l].num -= a[r].num;
        a[r].num = 0;
        r--;
    }else if(a[l].num < a[r].num){
        a[r].num -= a[l].num;
        a[l].num = 0;
        l++;
    }else{
        a[r].num = 0;
        a[l].num = 0;
        l++,r--;
    }
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].num >> a[i].ch;
    }
    int l = 1,r = n;
    while(l <= r){
        if(a[l].ch != a[r].ch){
            ans += min(a[l].num,a[r].num);
        }
        work(l,r);
    }
    cout << ans << "\n";
    return 0;
}