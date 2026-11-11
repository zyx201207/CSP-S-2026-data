#define MAXN 500002
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m;
long long a[MAXN];
long long sum[MAXN];

bool check(int x){
    for(int i = 0; i <= n - x; ++ i){
        int s = i, e = i + x - 1;
        long long w = sum[e] - sum[s] - s * (a[e] - a[s]);
        if(w <= m){
            return true;
        }
    }
    return false;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
 //   scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i){
  //      scanf("%d%d", &a[i]);
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++ i){
        sum[i] = sum[i - 1] + i * (a[i]- a[i - 1]);
    }
    if(sum[n - 1] <= m){
        cout << n << endl;
    //    printf("%d", n);
        return 0;
    }
    int left = 1, right = n;
    while(left < right){
        int mid = (left + right + 1) / 2;
        if(check(mid)){
            left = mid;
        }else
            right = mid - 1;
    }
    cout << left << endl;
  //  printf("%d", left);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
