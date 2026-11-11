#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005][2],l = -1,sum = -1,num = 0,mn = 0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n; cin >> n;
    for (int i = 0;i < n;i++){
        int y,z; cin >> z;
        char x; cin >> x;
        y = x - 'a' + 1;
        if (y == l){
            a[sum][1] += z;
        }
        else{
            sum++;
            a[sum][0] = y;
            a[sum][1] = z;
            l = y;
        }
        num += z;
    }
    if(num % 2 == 0){
        num /= 2;
    }
    else{
        num--;
        num /= 2;
    }
    int ss = 0,j = sum;
    for (int i = 0;i <= sum;i++){
        ss += a[i][1];
        if(i >= j){
            break;
        }
        else{
            if(a[i][0] == a[j][0]){
                if(a[i][1] > a[j][1]){
                    a[i][1] -= a[j][1];
                    j--;
                    i--;
                }
                else if(a[i][1] == a[j][1]){
                    j--;
                }
                else{
                    a[j][1] -= a[i][1];
                }
            }
            else{
                if(a[i][1] > a[j][1]){
                    a[i][1] -= a[j][1];
                    mn += a[j][1];
                    j--;
                    i--;
                }
                else if(a[i][1] == a[j][1]){
                    mn += a[j][1];
                    j--;
                }
                else{
                    a[j][1] -= a[i][1];
                    mn += a[i][1];
                }
            }
        }
    }
    cout << mn;
    return 0;
}
