#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2e5 + 5;
int n,a[M],sum,ans,k,cnt;
char s[M];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> s[i];
        ans += a[i];
    }for(int i = 1;i <= n;i++){
        sum += a[i];
        if(sum >= (ans + 1) / 2){
            k = i;
            break;
        }
    }int x = ans / 2 - sum + a[k];
    int y = a[k] - x - (ans % 2);
    int l = k - 1,r = k + 1;
    if(x > y){
        x -= y;
        while(x){
            if(x >= a[r]){
                x -= a[r];
                if(s[r] != s[k]) cnt += a[r];
                r++;
            }else{
                a[r] -= x;
                if(s[r] != s[k]) cnt += x;
                x = 0;
            }
        }
    }else{
        y -= x;
        while(y){
            if(y >= a[l]){
                y -= a[l];
                if(s[l] != s[k]) cnt += a[l];
                l--;
            }else{
                a[l] -= y;
                if(s[l] != s[k]) cnt += y;
                y = 0;
            }
        }
    }while(l >= 1 && r <= n){
        x = a[l];
        y = a[r];
        if(x > y){
            while(x){
                if(x >= a[r]){
                    x -= a[r];
                    if(s[r] != s[l]) cnt += a[r];
                    r++;
                }else{
                    a[r] -= x;
                    if(s[r] != s[l]) cnt += x;
                    x = 0;
                }
            }l--;
        }else{
            while(y){
                if(y >= a[l]){
                    y -= a[l];
                    if(s[l] != s[r]) cnt += a[l];
                    l--;
                }else{
                    a[l] -= y;
                    if(s[l] != s[r]) cnt += y;
                    y = 0;
                }
            }r++;
        }
    }cout << cnt;
    return 0;
}//RP++
