#include<bits/stdc++.h>
using namespace std;
long long n, sum, cnt, w, j;
struct node{
    long long num;
    char c;
};
node a[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].num >> a[i].c;
    }
    w = 1;
    j = n;
    while(w <= j){
        if(a[w].c == a[j].c){
            if(a[w].num > a[j].num){
                a[w].num -= a[j].num;
                j--;
            }
            else if(a[w].num < a[j].num){
                a[j].num -= a[w].num;
                w++;
            }
            else{
                w++;
                j--;
            }
        } else{
            if(a[w].num > a[j].num){
                cnt += a[j].num;
                a[w].num -= a[j].num;
                j--;
            }
            else if(a[w].num < a[j].num){
                cnt += a[w].num;
                a[j].num -= a[w].num;
                w++;
            }
            else{
                cnt += a[w].num;
                w++;
                j--;
            }
        }
    }
    cout << cnt;
    return 0;
}
