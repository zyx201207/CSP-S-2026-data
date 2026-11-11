#include<bits/stdc++.h>
using namespace std;

struct node{
    int num;
    char ch;
}a[200010];
int n, lft, rgt;
long long ans = 0;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        cin >> a[i].num >> a[i].ch;
    }
    lft = 1, rgt = n;
    while(true){
        if(lft == rgt || lft > rgt) break;
        if(a[lft].ch == a[rgt].ch){
            //cout << "same!\n";
            int chg = min(a[lft].num, a[rgt].num);
            a[lft].num -= chg;
            a[rgt].num -= chg;
        }
        else{
            int chg = min(a[lft].num, a[rgt].num);
            ans += chg;
            //cout << "nice!\n";
            a[lft].num -= chg;
            a[rgt].num -= chg;
        }
        if(a[lft].num == 0){
            lft++;
        }
        else if(a[rgt].num == 0){
            rgt--;
        }
    }
    cout << ans;
    return 0;
}