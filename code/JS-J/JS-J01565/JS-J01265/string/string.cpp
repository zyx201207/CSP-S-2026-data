#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long cnt;
struct node{
    int a;
    char c;
}x[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i].a >> x[i].c;
    int l = 1, r = n;
    while (l != r){
        if (x[l].c != x[r].c){
            if (x[l].a < x[r].a){
                x[r].a -= x[l].a;
                cnt += x[l].a;
                l++;
            }
            else {
                x[l].a -= x[r].a;
                cnt += x[r].a;
                r--;
            }
        }
        else{
            if (x[l].a < x[r].a){
                x[r].a -= x[l].a;
                l++;
            }
            else {
                x[l].a -= x[r].a;
                r--;
            }
        }
    }
    cout << cnt;
    return 0;
}
