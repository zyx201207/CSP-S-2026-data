#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
struct segement{
    int cnt;
    char c;
}a[N];
int n;
int slen = 0;
int hf = 0;
segement pre[N];
segement suf[N];
int pt, st;
int ans;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].cnt;
        cin >> a[i].c;
        slen += a[i].cnt;
    }
    hf = slen / 2;
    int now = 0;
    for(int i = 1;i <= n;i++){
        if(now + a[i].cnt <= hf){
            pt++;
            pre[pt].cnt = a[i].cnt;
            pre[pt].c = a[i].c;
            now += a[i].cnt;
        } else {
            int rest = hf - now;
            if(rest == 0) break;
            pt++;
            pre[pt].cnt = rest;
            pre[pt].c = a[i].c;
            break;
        }
    }
    now = 0;
    for(int i = n;i >= 1;i--){
        if(now + a[i].cnt <= hf){
            st++;
            suf[st].cnt = a[i].cnt;
            suf[st].c = a[i].c;
            now += a[i].cnt;
        } else {
            int rest = hf - now;
            if(rest == 0) break;
            st++;
            suf[st].cnt = rest;
            suf[st].c = a[i].c;
            break;
        }
    }
    int l = 1, r = 1;
    while(l <= pt && r <= st){
        if(pre[l].cnt > suf[r].cnt){
            if(pre[l].c == suf[r].c){
                pre[l].cnt -= suf[r].cnt;
                suf[r].cnt -= suf[r].cnt;
                r++;
            } else {
				ans += suf[r].cnt;
                pre[l].cnt -= suf[r].cnt;
                suf[r].cnt -= suf[r].cnt;
                r++;
            }
        } else if(pre[l].cnt < suf[r].cnt){
            if(pre[l].c == suf[r].c){
                suf[r].cnt -= pre[l].cnt;
                pre[l].cnt -= pre[l].cnt;
                l++;
            } else {
                ans += pre[l].cnt;
                suf[r].cnt -= pre[l].cnt;
                pre[l].cnt -= pre[l].cnt;
                l++;
            }
        } else {
            if(pre[l].c == suf[r].c){
                suf[r].cnt = 0;
                pre[l].cnt = 0;
                l++, r++;
            } else {
                ans += pre[l].cnt;
                suf[r].cnt = 0;
                pre[l].cnt = 0;
                l++, r++;
            }
        }
    }
    cout << ans;
    return 0;
}
