#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, sum, ans;
int a[200003];
char c[200003];
struct str{
    int num;
    char ch;
}l[200003], r[200003];
int lt, rt;
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)cin>>a[i]>>c[i], sum += a[i];
    //cout<<sum<<endl;
    int x = 1, cur = 0;
    while(cur + a[x] <= sum / 2)
        cur += a[x], l[++lt] = {a[x], c[x]}, x++;
    if(cur < sum / 2){
        l[++lt] = {sum / 2 - cur, c[x]};
        if(sum % 2 == 1){
            if(a[x] - sum / 2 + cur - 1 != 0)
                r[++rt] = {a[x] - sum / 2 + cur - 1, c[x]};
            x++;
        }
        else r[++rt] = {a[x] - sum / 2 + cur, c[x]}, x++;
    }
    else{
        if(sum % 2 == 1)
            r[++rt] = {a[x] - 1, c[x]}, x++;
    }
    while(x <= n)r[++rt] = {a[x], c[x]}, x++;
    reverse(r + 1, r + 1 + rt);
    int num = l[1].num, ln = 1, rn = 1;
    char cl = l[1].ch;
    int ri = r[1].num;
    char cr = r[1].ch;
    while(ln <= lt && rn <= rt){
        if(ri == 0)ri = r[rn].num, cr = r[rn].ch;
        if(num == 0)num = l[ln].num, cl = l[ln].ch;
        if(ri < num){
            num -= ri;
            rn++;
            if(cl != cr)ans += ri;
            ri = 0;
        }
        else{
            ri -= num;
            if(ri == 0)rn++;
            ln++;
            if(cl != cr)ans += num;
            num = 0;
        }
    }
    cout<<ans;
}
