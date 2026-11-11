#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
long long a[N];
char c[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long cnt = 0;
    char lc = ' ';
    while(n--){
        int x;
        char y;
        cin >> x >> y;
        if(y!=lc){
            cnt++;
            a[cnt] = x;
            c[cnt] = y;
            lc = y;
        }else{
            a[cnt]+=x;
        }
    }
    long long l=1,r=cnt;
    long long ln = a[1],rn = a[cnt];
    long long ans = 0;
    while(l<r){
        if(c[l] == c[r]){
            if(ln < rn){
                l++;
                rn-= ln;
                ln = a[l];
            }else if(ln > rn){
                r--;
                ln-= rn;
                rn = a[r];
            }else{
                l++;
                r--;
                ln = a[l];
                rn = a[r];
            }
        }else{
            if(ln < rn){
                l++;
                ans+=ln;
                rn-= ln;
                ln = a[l];
            }else if(ln > rn){
                r--;
                ans+=rn;
                ln-= rn;
                rn = a[r];
            }else{
                l++;
                r--;
                ans+=rn;
                ln = a[l];
                rn = a[r];
            }
        }
    }
    cout << ans;
    return 0;
}
