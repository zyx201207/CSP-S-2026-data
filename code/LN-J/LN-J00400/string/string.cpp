#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,l,r,sum,sl,sr,ans,fl;
char cl,cr;
pair<char,int> s[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s[i].second >> s[i].first;
        sum += s[i].second;
    }
    if(sum&1) fl = 1;
    sum/=2;
    while(sum-s[l].second > 0){sum -= s[l].second;l++;}
    r = l;
    sl = sum;
    cl = s[l].first;
    sr = s[l].second-sum-fl;
    cr = s[l].first;
    for(int cnt = 0;l > 0 && r <= n;){
            /*
        if(cnt <= 5){
            cerr << l << " " << sl << " " << cl << endl;
            cerr << r << " " << sr << " " << cr << endl;
            cerr << "---bee ccf" << endl;
        }*/
        if(cl != cr) ans += min(sl,sr);
        if(sl < sr){
            sr -= sl;
            l--;
            sl = s[l].second;
            cl = s[l].first;
            //if(cnt <= 5)cerr << 111 << " " << s[l].second << endl;
        }
        else if(sl == sr){
            l--;
            sl = s[l].second;
            cl = s[l].first;
            r++;
            sr = s[r].second;
            cr = s[r].first;
        }
        else {
            sl -= sr;
            r++;
            sr = s[r].second;
            cr = s[r].first;
        }
    /*
        if(cnt <= 5){
            cerr << l << " " << sl << " " << cl << endl;
            cerr << r << " " << sr << " " << cr << endl;
            cerr << "---" << endl;
        }*/
    }
    if(cl != cr) ans += min(sl,sr);
    cout << ans << endl;
    return 0;
}
//I want CSP-S 200+  thank the best CCF
