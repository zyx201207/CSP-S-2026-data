#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char b[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
    }
    int l = 1,r = n,x = a[1],y = a[n];
    while(l < r){
        if(b[l] == b[r]){
            if(x <= y){
                y -= x;
                l++;
                x = a[l];
            }else if(x == y){
                l++;
                r--;
                x = a[l];
                y = a[r];
            }else{
                x -= y;
                r--;
                y = a[r];
            }
        }else{
            if(x <= y){
                ans += x;
                y -= x;
                l++;
                x = a[l];
            }else if(x == y){
                ans += x;
                l++;
                r--;
                x = a[l];
                y = a[r];
            }else{
                x -= y;
                ans += y;
                r--;
                y = a[r];
            }
        }
    }
    cout << ans;
    return 0;
}
