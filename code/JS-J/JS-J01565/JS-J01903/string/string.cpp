#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct zf{
    long long sl;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++){
        cin >> a[i].sl >> a[i].c;
    }
    long long ans = 0;
    int i = 1,j = n;
    while(n--){
        if(a[i].c != a[j].c){
            ans += min(a[i].sl,a[j].sl);
            if(a[j].sl >= a[i].sl){
                a[i].c = a[j].c;
                a[j].sl -= a[i].sl;
                i++;
            } else {
                a[j].c = a[i].c;
                a[i].sl -= a[j].sl;
                j--;
            }
        }
    }
    cout << ans;
    return 0;
}
