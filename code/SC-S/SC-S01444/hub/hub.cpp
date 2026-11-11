#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int inf = 1e9+7;

mt19937_64 rnd(time(0));

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);
    int c, T; cin>>c>>T;
    while(T --){
        int n, k; cin>>n>>k;
        cout<< rnd()%n <<"\n";
    }
    return 0;
}