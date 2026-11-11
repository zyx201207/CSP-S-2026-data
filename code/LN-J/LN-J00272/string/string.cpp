#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
    int x;
    char s;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].s;
    }
    int j = 0;
    int i = 1;
    int id = 1;
    bool t = 0;
    int f = a[1].x;
    while(i<n-j){
        if(t==0){
            if(a[id].s != a[n-j].s){
                ans += min(f,a[n-j].x);
            }
            f = f-a[n-j].x;
            if(f < 0){
                f = abs(f);
                id = n-j;
                t = 1;
                i++;
            }else if(f > 0){
                j++;
            }else{
                i++;
                j++;
                id = i;
                f = a[i].x;
            }
        }else{
            if(a[id].s != a[i].s){
                ans += min(f,a[i].x);
            }
            f = f-a[i].x;
            if(f < 0){
                f = abs(f);
                id = i;
                t = 0;
                j++;
            }else if(f > 0){
                i++;
            }else{
                i++;
                j++;
                t = 0;
                id = i;
                f = a[i].x;
            }
        }
    }
    cout << ans;
    return 0;
}
