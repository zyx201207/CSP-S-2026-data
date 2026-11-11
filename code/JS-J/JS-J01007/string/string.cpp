#include<bits/stdc++.h>
using namespace std;
struct nood{
    long long l,r;
    char a;
}a[200005],b[200005];
long long n,sum,l,r,t,na,nb,ans;
string s;
bool cmp(nood x,nood y){
    return x.l < y.l;
}
long long maxn1e18 = 1000000000000000000;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i].r >> a[i].a;
        a[i].l = sum+1;
        sum += a[i].r;
        a[i].r = sum;
    }
    if (sum > 1e7){
    //cout << sum <<"\n";
    for (int i = 1;i <= n;i++){
        if (a[i].r > sum/2){
            if (a[i].l <= (sum+1)/2){
                a[++na] = {a[i].l,sum/2,a[i].a};
                b[++nb] = {sum-a[i].r+1,sum/2,a[i].a};
            }
            else {
                b[++nb] = {sum-a[i].r+1,sum-a[i].l+1,a[i].a};
                //a[i] = {maxn1e18,maxn1e18,'#'};
            }
        }else
            na = i;
    }
    //cout << na << ' ' << nb;
    sort(a+1,a+1+na,cmp);
    sort(b+1,b+1+nb,cmp);
    if (a[na].l > a[na].r){
        na -= 1;
    }
    if (b[nb].l > b[nb].r){
        nb -= 1;
    }//*/
    /*for (int i = 1;i <= na;i++){
        cout << a[i].l << ' ' << a[i].r << ' ' << a[i].a << '\n';
    }
    cout << '\n';
    for (int i = 1;i <= nb;i++){
        cout << b[i].l << ' ' << b[i].r << ' ' << b[i].a << '\n';
    }//*/
    long long k = 0;
    int j = 1;
    for (int i = 1;i <= na;i++){
        while(j <= nb && b[j].r < a[i].r){
            if (b[j].a != a[i].a){
                ans += b[j].r-k;
            }
            k = b[j].r;
            //cout << k << ' ';
            j += 1;
        }
        if (b[j].a != a[i].a){
            ans += a[i].r-k;
        }
        k = a[i].r;
        //cout << k << ' ';
    }
    cout << ans;
    }
    else{
        for (int i = 1;i <= n;i++){
            for (long long j = a[i].l;j <= a[i].r;j++){
                s += a[i].a;
            }
        }
        for (long long i = 0;i < sum/2;i++){
            ans += (s[i] != s[sum-i-1]);
        }
        cout << ans;
    }
    return 0;
}
