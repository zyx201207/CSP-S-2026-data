#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int v , x , id;
    string s;
}w[100001];
bool cmp(node x , node y){
    if(x.x != y.x) return x.x > y.x;
    if(x.v != y.v) return x.v > y.v;
    return x.id < y.id;
}
string to2(long long x){
    string ans = "";
    while(x){
       ans += char(x % 2 + '0');
       x >>= 1;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
long long fun(string a){
    long long cnt = 0;
    for(int i = 0 ; i < a.size() ; i ++){
        if(a[i] == '0') return cnt;
        cnt ++;
    }
    return cnt;
}
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n , m , a , l = 0;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a;
        w[i].v = a;
        w[i].s = to2(a);
        w[i].id = i;
        l = max(l , (long long)w[i].s.size());
    }
    for(int i = 1 ; i <= n ; i ++){
        if(w[i].s.size() != l) w[i].s = '0' + w[i].s;
        w[i].x = fun(w[i].s);
    }
    sort(w + 1 , w + n + 1 , cmp);
    long long ans = w[1].v;
    for(int i = 1 ; i <= m ; i ++){
        ans &= w[i].v;
    }
    cout << ans;
    return 0;
}
