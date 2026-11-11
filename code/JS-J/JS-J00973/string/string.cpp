#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N = 2e5 + 10;
struct Node{
    int num;
    char c;
}a[N];
int tot = 0,lt,rt;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i ++ ){
        cin >> a[i].num >> a[i].c;
    }
    int l = 1,r = n;
    lt = a[l].num,rt = a[r].num;
    while(l < r){
        if(a[l].c != a[r].c){
            if(a[l].num == a[r].num){
                tot += a[l].num;
                l ++,r --;
            }
            else if(lt < rt){
                tot += lt;
                int i = l;
                for(;i ++ ;i <= r){
                    if(lt + a[i].num < rt){
                        if(a[i].c != a[r].c){
                            tot += a[i].num;
                        }
                        lt += a[i].num;
                    }else{
                        int k = a[i].num + lt - rt;
                        if(a[i].c != a[r].c){
                            tot += (rt - lt);
                        }
                        lt = rt;
                        a[i].num -= k;
                        break;
                    }
                }
                l = i;
                r --;
            }
            else{
                tot += rt;
                int i = r;
                for(;i -- ;i >= l){
                    if(rt + a[i].num < lt){
                        if(a[i].c != a[l].c){
                            tot += a[i].num;
                        }
                        rt += a[i].num;
                    }else{
                        int k = a[i].num + rt - lt;
                        if(a[i].c != a[l].c){
                            tot += (lt - rt);
                        }
                        rt = lt;
                        a[i].num = k;
                        break;
                    }
                }
                r = i;
                l ++;
            }
        }else{
            if(a[l].num == a[r].num){
                l ++;
                r --;
            }
            else if(a[l].num < a[r].num){
                a[r].num -= a[l].num;
                l ++;
            }else{
                a[l].num -= a[r].num;
                r --;
            }
        }
        lt += a[l].num;
        rt += a[r].num;
    }
    cout << tot << endl;
   return 0;
}
