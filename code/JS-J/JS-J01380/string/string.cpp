#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 2e5 + 5;
ll n;
ll a[maxn];
char c[maxn];
ll len[maxn];
ll l, r;
ll li, ri;
ll temp, midnum;
ll ans = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    len[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        len[i] = len[i-1] + a[i];
    }

    l = 1;
    r = len[n];
    li = 1;
    ri = n;
    temp = 0;
    while(l < r && li < ri){
        if(ri - li == 1){
            break;
        }
        if(c[li] == c[ri]){
            if(len[li] - l + 1 < r - len[ri - 1]){
                li = li + 1;
                temp = l;
                l = len[li - 1] + 1;
                r -= (l - temp);
            }else if(len[li] - l + 1 == r - len[ri - 1]){
                li = li + 1;
                ri = ri - 1;
                l = len[li - 1] + 1;
                r = len[ri];
            }else{
                ri = ri - 1;
                temp = r;
                r = len[ri];
                l += (temp - r);
            }
        }else{
            if(len[li] - l + 1 < r - len[ri - 1]){
                li = li + 1;
                temp = l;
                l = len[li - 1] + 1;
                r -= (l - temp);
                ans += (l - temp);
            }else if(len[li] - l + 1 == r - len[ri - 1]){
                li = li + 1;
                ri = ri - 1;
                temp = l;
                l = len[li - 1] + 1;
                r = len[ri];
                ans += (l - temp);
            }else{
                ri = ri - 1;
                temp = r;
                r = len[ri];
                l += (temp - r);
                ans += (temp - r);
            }
        }
    }
    if(l < r && ri - li == 1 && c[ri] != c[li]){
        if((l + r) % 2 == 0 ){
            midnum = (l + r) / 2;
            if(midnum <= len[li]){
                ans += (r - len[ri - 1]);
            }else{
                ans += (len[li] - l + 1);
            }
        }else{
            midnum = (l + r) / 2;
            midnum += 1;
            if(midnum <= len[li]){
                ans += (r - len[ri - 1]);
            }else if(midnum == len[li] + 1){
                ans += (len[li] - l + 1);
            }else{
                ans += (len[li] - l + 1);
            }
        }
    }
    cout << ans << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
