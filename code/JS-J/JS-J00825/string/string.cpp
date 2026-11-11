#include<iostream>
#include<cmath>
#define int long long
using namespace std;

struct A{
    int l;
    char c;
};

int n;
A a[200005]={};

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].c;
    }

    int cnt = 0;
    int l = 1, r = n;

    while((l!=r)&&(l < r)){
        if(a[l].l==a[r].l){
            if(a[l].c!=a[r].c){cnt += a[l].l;}
            l++;r--;
            continue;
        }
        if(a[l].l > a[r].l){
            if(a[l].c!=a[r].c){cnt += a[r].l;}
            a[l].l-=a[r].l;r--;
            continue;
        }
        if(a[l].l < a[r].l){
            if(a[l].c!=a[r].c){cnt += a[l].l;}
            a[r].l-=a[l].l;l++;
            continue;
        }
    }

    cout << cnt;
    return 0;
}
