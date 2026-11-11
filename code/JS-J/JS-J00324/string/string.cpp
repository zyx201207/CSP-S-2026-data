#include<bits/stdc++.h>
using namespace std;
struct node{
    int a ;
    char b;
}a[200005];
node b[200005];
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].a >> a[i].b;
        sum += a[i].a;
    }
    for(int i = 1 ; i <= n ; i++){
        b[n-i+1].a = a[i].a;
        b[n-i+1].b = a[i].b;
    }
    long long la = a[1].a , lb = b[1].a;
    long long ai = 1 , bi = 1;
    long long num = 0;
    long long ans = 0;
    //if(sum % 2 == 1)sum++;
    while(num < sum){
        if(a[ai].b == b[bi].b){
            if(la >= lb){
                num = lb;
                lb += b[++bi].a;
            }
            else{
                num = la;
                la += a[++ai].a;
            }
        }
        else{
            if(la >= lb){
                ans += lb - num;
                num = lb;
                lb += b[++bi].a;
            }
            else{
                ans += la - num;
                num = la;
                la += a[++ai].a;
            }
        }
    }
    cout << ans / 2;
    return 0;
}
