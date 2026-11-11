#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ull unsigned long long
#define pb push_back
#define mii map<int,int>
#define pii pair<int,int>
#define si stack<int,int>
#define qi queue<int,int>
#define miao return 0;
using namespace std;

const signed int N = 2e5+5;

int n;

string strs;
bool flag = 1;

struct node{
    int a;
    char c;
}s[N];
int cnt = 0;

bool check(string s,int cnt){
    string s2;
    for(int i=cnt-1;i>=0;i--){
        s2.pb(s[i]);
    }

    if(s2 == s) return 1;
    else return 0;
}

int pf(){
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].a;j++){
            strs.pb(s[i].c);
            cnt++;
        }
    }

    if(check(strs,cnt)) return 0;

    int ans = 0;
    int l=0,r=cnt-1;
    for(int i=0;i<cnt;i++){
        if(strs[l] != strs[r]) ans++;
        if(l == r) break;
        if(l+1 == r) break;
        l++;r--;
    }

    return ans;
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    char lc;
    int ls;
    bool flag2 = 1;
    for(int i=0;i<n;i++){
        cin >> s[i].a >> s[i].c;
        if(i != 0 && s[i].c != lc) flag = 0;
        if(i != 0 && s[i].a != ls) flag2 = 0;
        lc = s[i].c;
        ls = s[i].a;
    }
    if(flag){
        cout << 0 << endl;
        miao
    }

    if(flag2){
        for(int i=0;i<n;i++){
            strs.pb(s[i].c);
            cnt++;
        }

        if(check(strs,cnt)){
            cout << 0 << endl;
            miao
        }

        int ans = 0;
        int l=0;int r=cnt-1;
        for(int i=0;i<cnt;i++){
            if(strs[l] != strs[r]) ans++;
            if(l == r) break;
            if(l+1 == r) break;
            l++;r--;
        }

        cout << ans * s[0].a << endl;
        miao
    }

    cout << pf() << endl;

    miao
}