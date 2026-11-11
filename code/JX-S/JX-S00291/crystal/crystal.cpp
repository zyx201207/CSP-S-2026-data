#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int N = 5e5 + 5;

int n, k, T, ans, sum;
ll m, a[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int l = 1;
    ll lst = a[1];
    for(int i = 1; i <= n;){
        int sam = 0, j = i;
        sum = 0;
        ll cha = a[i] - lst;
        while(j <= n && a[j] == a[i]) j++, sam++;

        while(l < i && cha * 1ll * (i - l) > m){
            m += (lst - a[l]);
            l++;
        }

        if(l != i) m -= cha * 1ll * (i - l);
        sum = sam + (i - l);
        ans = max(ans, sum);
        lst = a[i];
        i = j;
       // cout << m << endl;
    }
    cout << ans;
    return 0;
}

// zui hou yi nian le miao~ luogu:_Memory, ju ruo gan jue zui hou yi nian bu xie dian zhu shi mei yi si
//ke shi yi si you dian xie bu wan bao li...bei zi ji cai kuQAQ, jiang jiu kan ba
//wo de tong xue shuo ta yao quan wen bei song recall, bu zhi dao ta you mei you cheng gong!
//CSP2026 rp++!!
