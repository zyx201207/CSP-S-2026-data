#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10 , INF = 1e18 , mod = 1e9 + 7;
long long cnt[MAXN];
char c[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; ++i){
        cin>>cnt[i]>>c[i];
    }
    long long i = 1 , j = n , cnti = cnt[1] , cntj = cnt[n] , ans = 0;
    while(i < j){
        if(c[i] == c[j]){
            if(cnti < cntj){
                cntj -= cnti;
                i++;
                cnti = cnt[i];
            }
            else if(cnti == cntj){
                i++;
                j--;
                cnti = cnt[i];
                cntj = cnt[j];
            }
            else{
                cnti -= cntj;
                j--;
                cntj = cnt[j];
            }
        }
        else{
            if(cnti < cntj){
                ans += cnti;
                cntj -= cnti;
                i++;
                cnti = cnt[i];
            }
            else if(cnti == cntj){
                ans += cnti;
                i++;
                j--;
                cnti = cnt[i];
                cntj = cnt[j];
            }
            else{
                ans += cntj;
                cnti -= cntj;
                j--;
                cntj = cnt[j];
            }
        }
    }
    cout<<ans;
    return 0;
}
