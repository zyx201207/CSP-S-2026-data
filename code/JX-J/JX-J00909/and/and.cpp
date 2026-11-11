#include <bits/stdc++.h>
using namespace std;

long long n, m, a[325799], ans;
string l;

bool cmp(long long a, long long b){
    return a>b;
}

string er(long long n){
    string s;
    while (n){
        s+=char(n%2+'0');
        n/=2;
    }
    return s;
}

string yu(string a, string b){
    int len1 = a.size();
    int len2 = b.size();
    string s;
    for (int i=0; i<=min(len1, len2)-1; i++){
        if (a[i] == '1' && b[i] == '1') s+='1';
        else s+='0';
    }
    return s;
}
long long shi(string s){
    int len = s.size();
    long long sum = 0;
    for(int i=0; i<=len-1; i++){
        sum += (s[i]-'0')*pow(2, i);
    }
    return sum;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1, cmp);
    if (m == 1){
        long long maxn = 0;
        for (int i=2; i<=n; i++) maxn = max(maxn, a[i]);
        cout << maxn;
        return 0;
    }
    ans = a[1];
    for (int i=2; i<=m; i++){
        ans = shi(yu(er(ans), er(a[i])));
    }
    cout << ans;

    return 0;
}
