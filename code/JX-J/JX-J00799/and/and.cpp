#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
ull awy(ull a,ull b){
    ull cnt = 1;
    ull ans = 0;
    while(a != 0 || b != 0){
        ans += cnt * (a % 2 & b % 2);
        cnt *= 2;
        a /= 2;
        b /= 2;
    }
    return ans;
}
int n,m;
ull a[200001];
bool cmp(ull a,ull b){
    return a > b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    ull ans = a[0];
    for(int i=1;i<m;i++){
        ans = awy(ans,a[i]);
    }
    cout << ans;
}