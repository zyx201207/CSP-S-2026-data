#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    unsigned long long n,m,maxn = -INT_MAX,a[1000000];
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        maxn = max(maxn,a[i]);
    }
    if(m == 1){
        cout<<maxn;
        return 0;
    }
    else if(m == 2){
        maxn = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i != j)maxn = max(maxn,a[i] & a[j]);
            }
        }
        cout<<maxn;
    }else if(m == n){
        unsigned long long x = a[1];
        for(int i = 2;i <= n;i++){
            x = x & a[i];
        }
        cout<<x;
    }else if(m == n - 1){
        for(int i = 1;i <= n;i++){
            unsigned long long x = (i == 1?a[2]:a[1]);
            for(int j = 1;j <= n;j++){
                if(j != i)x & a[i];
            }
            maxn = max(maxn,x);
        }
        cout<<maxn;
    }else if(maxn == 4){
        int ji = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] % 2 == 1)ji++;
        }
        cout<<(ji >= m?"1":"0");
    }else{
        sort(a + 1,a + n + 1);
        maxn = a[n];
        for(int i = n - 1;i >= n - m + 1;i--){
            maxn = maxn & a[i];
        }
        cout<<maxn;
    }
    return 0;
}
