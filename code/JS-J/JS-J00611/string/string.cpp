#include <iostream>
#include <vector>
#define mas 200010
#define int long long
using namespace std;

struct s{
    char c;
    int sz;
    int l, r;
};

int n;
vector<s> a;

bool lfast(int l, int r){
    return (l>(a.size()-r+1));
}

int solve(){
    int ans=0;
    int rest=0;
    int l, r; l=1; r=a[a.size()-1].r;
    int le, re; le=0; re=a.size()-1;

    while (l<r){
        if (l>a[le].r) le++;
        if (r<a[re].l) re--;
        // cout << l << " " << r << " " << le << " " << re << endl;
        if (le>=re) break;
        int cmplen=min(a[le].r-l+1, r-a[re].l+1);
        ans+=cmplen*(a[le].c!=a[re].c);
        l+=cmplen; r-=cmplen;
    }

    return ans;
}

signed main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    
    cin >> n;
    
    for (int i=1;i<=n;i++){
        int sz; char c; cin >> sz >> c;
        if (a.empty()) {
            a.push_back({c, sz, 1, sz});
            continue;
        }
        if (a[a.size()-1].c==c){
            a[a.size()-1].sz+=sz;
            a[a.size()-1].r+=sz;
        }
        else a.push_back({c, sz, a[a.size()-1].r+1, a[a.size()-1].r+sz});
    }

    // for (auto x:a){
    //     cout << x.l << " " << x.r << endl;
    // }

    cout << solve() << endl;



    return 0;
}