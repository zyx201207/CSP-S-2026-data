#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct node{
    ll num;
    char c;
} a[262144];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].c;
        sum += a[i].num;
    }
    ll need = sum/2;
    ll ans = 0;
    ll l = 0;
    ll r = n-1;
    while(need>0){
        if(a[r].num >= a[l].num){
            if(a[l].num >= need){
                if(a[r].c == a[l].c){
                    need = 0;
                    break;
                }
                else{
                    ans += need;
                    need = 0;
                    break;
                }
            }
            else{
                if(a[r].c == a[l].c){
                    need -= a[l].num;
                    a[r].num -= a[l].num;
                    l ++;
                    continue;
                }
                else{
                    ans += a[l].num;
                    need -= a[l].num;
                    a[r].num -= a[l].num;
                    l ++;
                    continue;
                }
            }
        }
        else{
            if(a[r].num >= need){
                if(a[r].c == a[l].c){
                    need = 0;
                    break;
                }
                else{
                    ans += need;
                    need = 0;
                    break;
                }
            }
            else{
                if(a[r].c == a[l].c){
                    need -= a[r].num;
                    a[l].num -= a[r].num;
                    r --;
                    continue;
                }
                else{
                    ans += a[r].num;
                    need -= a[r].num;
                    a[l].num -= a[r].num;
                    r --;
                    continue;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
