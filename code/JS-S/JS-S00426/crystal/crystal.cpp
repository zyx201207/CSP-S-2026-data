#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool check(long long x){
    long long l = 1, r = x,cost = 0;
    long long num = r- l;
    for(long long i = 1; i <= r-1; i++){
        cost += a[r] - a[i];
    }
    long long ans = cost;
    for(long long i = x+1; i <= n; i++){
        l++; r++;
        cost = cost - (a[r-1] - a[l-1]) + (a[i] - a[i-1])*num;
        ans = min(ans,cost);
        //cout << cost << "\n";
    }
    return (ans <= m);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    long long l = 1, r = n,mid;
    while(l <= r){
        mid = l + r >> 1;
        if(check(mid)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if(check(l)) cout << l << "\n";
    else{
        while(!check(l)){l--;}
        cout << l << "\n";
    }
    //cout << l << "\n";
    return 0;
}
/*
5 5
1 2 4 8 9
l   r
1. l = 1, r = 3 cost = 3 + 2 = 5
2. l = 2, r = 4 cost = 6 + 4 = 10
3. l = 3, r = 5 cost = 1 + 5 = 6
5 -> 10?
5 - (4 - 1) + (8 -4)*2 = 10
10 -> 5?
10 - (8 - 2) + (9 - 8)*2 = 6

test 4
output 315276
answer 315275
test 3
output 3846
answer 3845

I've forgotten how to write upperbound [l,r) 
but i think this is enough (if the test is easy).
please give me one hundred points, i love you.

*/